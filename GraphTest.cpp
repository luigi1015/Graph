#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include "Vertex.cpp"
#include "Edge.h"
#include "Graph.cpp"

class GraphTest : public CppUnit::TestCase 
{
	private:
		
	public:
		void testCreateGraph()
		{//Basic test of creating a graph.
			//Set up the graph.
			Graph::Graph<int> g;
			
			//Create a vertex in the graph
			g.addVertex( 1, 2 );
			
			//Verify the values.
			CPPUNIT_ASSERT( g.getNumVertices() == 1 );
			CPPUNIT_ASSERT( g.getVertex(1).getID() == 1 );
			CPPUNIT_ASSERT( g.getVertex(1).getValue() == 2 );
		}
		
		//Create the test suite using CPPUnit macros.
		CPPUNIT_TEST_SUITE( GraphTest );
		CPPUNIT_TEST( testCreateGraph );
		CPPUNIT_TEST_SUITE_END( );
};

int main()
{
	CPPUNIT_TEST_SUITE_REGISTRATION( GraphTest );
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry( );
	runner.addTest( registry.makeTest( ) );
	if ( runner.run( ) )
	{//Runner had success.
		return 0;
	}
	else
	{//Runner failed.
		return 1;
	}
}
