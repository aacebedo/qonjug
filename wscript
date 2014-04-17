# Build file for qonjug project

import os
from waflib import Logs

APPNAME = 'qonjug'
VERSION = '0.1.0'

top = '.'
out = 'build'

def addLibraryPath(conf,libName,path,onlyHeaders = False):
  if path != None:
    relPathNode = conf.path.find_dir(path)
    absPathNode = conf.root.find_dir(path)
    resPath = None
    
    
    Logs.pprint('WHITE','{0: <40}'.format('Library \''+libName+'\' will be searched in '),sep=': ')
    if relPathNode == None and absPathNode == None :   
       Logs.pprint('RED','Library path \''+path+'\' for \''+libName+'\' does not exist, value will be ignored')
    else :
      if absPathNode == None:
        resPath = relPathNode
      else:
        resPath = absPathNode             
      
      conf.env['LIBPATH_'+libName.upper()] = []
      conf.env['LIBPATH_'+libName.upper()].append(os.path.join(resPath.abspath(),'lib'))
      conf.env['INCLUDES_'+libName.upper()] = []
      conf.env['INCLUDES_'+libName.upper()].append(os.path.join(resPath.abspath(),'include'))
     
      Logs.pprint('GREEN',resPath.abspath())
  
  if onlyHeaders == False:     
    conf.check_cxx(lib=libName, use_lib=libName.upper(),libpath=conf.env['LIBPATH_'+libName.upper()])
      
def initializeConfigurations(conf):
  env = conf.env
  conf.setenv('debug',env)
  conf.env.CXXFLAGS = ['-g']
    
  conf.setenv('release',env)
  conf.env.CXXFLAGS = ['-O3']
  
def init(ctx):
  global out
  if ctx.options.mode != 'debug' and ctx.options.mode != 'release' :
    ctx.fatal("Mode is invalid, shall be release or debug")
    
  out = os.path.join('build',ctx.options.mode)

def options(opt):  
  opt.load('compiler_cxx')   
  opt.add_option('--with-sqlite3', action='store', default=None, help='Path to SQLite 3 library')
  opt.add_option('--with-log4cxx', action='store', default=None, help='Path to log4cxx library')
  opt.add_option('--with-kompex', action='store', default=None, help='Path to kompex library')
  opt.add_option('--with-tclap', action='store', default=None, help='Path to tclap library')
  
  opt.add_option('--mode', action='store', default="debug", help='target: [debug|release] ')  
    
def configure(conf):
  conf.load('compiler_cxx')   
 
  conf.env.LIBPATH = []
    
  addLibraryPath(conf,'sqlite3',conf.options.with_sqlite3)
  addLibraryPath(conf,'log4cxx',conf.options.with_log4cxx)
  addLibraryPath(conf,'kompex',conf.options.with_kompex)
  addLibraryPath(conf,'tclap',conf.options.with_tclap,True)

  
  conf.check(header_name=os.path.join('log4cxx','log4cxx.h'))
  conf.check(header_name='sqlite3.h')
  conf.check(header_name=os.path.join('tclap','CmdLine.h')) 
  conf.check(header_name='KompexSQLiteDatabase.h',includes=conf.env.INCLUDES_KOMPEX)
  
  initializeConfigurations(conf)
  
def build(bld):    
  bld.env = bld.all_envs['release']
  
  srcdir = bld.path.find_dir('src')
  
  bld.program(
    source=srcdir.ant_glob('**/*.cpp'), 
    target='qonjug',
    includes = [srcdir],
    vnum=VERSION,
    use=['KOMPEX','SQLITE3','LOG4CXX']
    
  )
  
  
  