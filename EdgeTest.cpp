#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include "Edge.h"

class EdgeTest : public CppUnit::TestCase 
{
	private:
		
	public:
		void testCreateEdge()
		{//Basic test of creating the edge.
			//Set up the Edge.
			Graph::Edge ed(1, 2, 3);
			
			//Verify the values.
			CPPUNIT_ASSERT( ed.getWeight() == 1 );
			CPPUNIT_ASSERT( ed.getStartVertex() == 2 );
			CPPUNIT_ASSERT( ed.getEndVertex() == 3 );
		}

		void testModifyEdge()
		{//Basic test of modifying the edge.
			//Set up the Edge.
			Graph::Edge ed(1, 2, 3);
			
			//Change the values up using the methods.
			ed.setWeight( 4 );
			ed.setStartVertex( 5 );
			ed.setEndVertex( 6 );
			
			//Verfiy the values.
			CPPUNIT_ASSERT( ed.getWeight() == 4 );
			CPPUNIT_ASSERT( ed.getStartVertex() == 5 );
			CPPUNIT_ASSERT( ed.getEndVertex() == 6 );
		}
		
		//Create the test suite using CPPUnit macros.
		CPPUNIT_TEST_SUITE( EdgeTest );
		CPPUNIT_TEST( testCreateEdge );
		CPPUNIT_TEST( testModifyEdge );
		CPPUNIT_TEST_SUITE_END( );
};

int main()
{
	CPPUNIT_TEST_SUITE_REGISTRATION( EdgeTest );
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
