#include <iostream>
#include "CStackFile.h"


// Arguments as string for syntax info
#define SYNTAXSTR "[--dumprawblocks] [--nostatus] <originalStackPath>"


int main( int argc, char * const argv[] )
{
    CStackFile		theStack;
	
	if( argc < 2 )
	{
		fprintf( stderr, "Error: Syntax is %s " SYNTAXSTR "\n", argv[0] );
		return 2;
	}
	
	bool	dumpRawBlockData = false,
			noStatusMessages = false;
	int		x = 1;	// Skip command name in argv[0].
	if( argc > 2 )
	{
		for( ; x < argc; x++ )
		{
			if( strcmp(argv[x],"--dumprawblocks") == 0 )
				dumpRawBlockData = true;
			else if( strcmp(argv[x],"--nostatus") == 0 )
				noStatusMessages = true;
			else if( argv[x][0] == '-' )
			{
				fprintf( stderr, "Error: Unknown option %s, syntax is %s " SYNTAXSTR "\n", argv[x], argv[0] );
				return 3;
			}
			else	
				break;
		}
	}
	
	if( x >= argc )	// Only options, no file path?
	{
		fprintf( stderr, "Error: Syntax is %s " SYNTAXSTR "\n", argv[0] );
		return 2;
	}
	
	const char*	fpath = argv[x];
	if( !theStack.LoadFile( fpath, dumpRawBlockData, !noStatusMessages ) )
	{
		fprintf( stderr, "Error: Conversion of '%s' incomplete/failed.\n", fpath );
		return 5;
	}
	
    return 0;
}
