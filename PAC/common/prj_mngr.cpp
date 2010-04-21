#include <string.h>

#include "prj_mngr.h"
#include "wago.h"
#include "PAC_dev.h"

project_manager* project_manager::instance;
//-----------------------------------------------------------------------------
int project_manager::load_configuration( char *file_name )
    {
#ifdef DEBUG
    Print( "Reading description from %s....\n", file_name );
#endif // DEBUG

    if ( cfg_file->open( file_name ) != 0 )
    	{
#ifdef DEBUG
        Print( "project_manager:load_configuration(...) - file not found!\n" );            
#endif // DEBUG
        while ( 1 ) { }
    	}

    const *char SIGNATURE            = "WG {4B714C08-9602-4130-8563-4B51E08BB9D7}";
    const int   SIGNATURE_SIZE       = 42;    
    char        id[ SIGNATURE_SIZE ] = { 0 };
    
    cfg_file->read( id, SIGNATURE_SIZE - 1 );
    if ( strcmp( id, SIGNATURE ) != 0 )
        {
#ifdef DEBUG
        Print( "project_manager:load_configuration(...) - not correct file format!\n" );            
#endif // DEBUG
        while ( 1 ) { }
        }
        
    //-Editor editor_version.
    const int CURRENT_EDITOR_VERSION = 12;
    int       editor_version = 0;

    sscanf( cfg_file->get_line(), "%d", &editor_version );
    if ( editor_version < CURRENT_EDITOR_VERSION )
        {
#ifdef DEBUG
        Print( "project_manager:load_configuration(...) - not correct editor editor_version - %d, must be %d!\n",
            editor_version, CURRENT_EDITOR_VERSION );
#endif // DEBUG
        while ( 1 ) { }
        }

    //-File editor_version.
    int file_version = 0;

    sscanf( cfg_file->get_line(), "%d", &file_version );
#ifdef DEBUG
    Print( "Editor version - %d.\n, editor_version" );
    Print( "File version - %d.\n, file_version" );
#endif // DEBUG

    //-Wago data.
    wago_manager::get_instance()->load_from_cfg_file( cfg_file );

    //-Devices data.
    device_manager::get_instance()->load_from_cfg_file( cfg_file );

    cfg_file->close();
    }
//-----------------------------------------------------------------------------
project_manager* project_manager::get_instance()
    {
    return instance;
    }
//-----------------------------------------------------------------------------
void project_manager::set_instance( project_manager* new_instance )
    {
    instance = new_instance;
    }
//-----------------------------------------------------------------------------