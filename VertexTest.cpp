#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include "Vertex.cpp"

class VertexTest : public CppUnit::TestCase 
{
	private:
		
	public:
		void testCreateVertex()
		{//Basic test of creating a vertex.
			//Set up the vertex.
			Graph::Vertex<int> v(1, 2);
			
			//Verify the values.
			CPPUNIT_ASSERT( v.getID() == 1 );
			CPPUNIT_ASSERT( v.getValue() == 2 );
			CPPUNIT_ASSERT( v.getNumEdges() == 0 );
		}

		void testChangeVertex()
		{//Basic test of changing vertex values and IDs.
			//Set up the vertex.
			Graph::Vertex<int> v(1, 2);
			
			//Verify the values.
			CPPUNIT_ASSERT( v.getID() == 1 );
			CPPUNIT_ASSERT( v.getValue() == 2 );
			CPPUNIT_ASSERT( v.getNumEdges() == 0 );
			
			//Change the values
			v.setID( 3 );
			v.setValue( 4 );
			
			//Verify the new values.
			CPPUNIT_ASSERT( v.getID() == 3 );
			CPPUNIT_ASSERT( v.getValue() == 4 );
			CPPUNIT_ASSERT( v.getNumEdges() == 0 );
		}

		void testVertexWithEdge()
		{//Basic test of create a vertex with an edge.
			//Set up the vertex and the edge.
			Graph::Edge ed(1, 1, 2);
			Graph::Vertex<int> v(1, 2);
			
			//Verify the vertex has no edges yet.
			CPPUNIT_ASSERT( v.getNumEdges() == 0 );

			//Add the edge.
			v.addEdge( ed );
			
			//Verfiy the edge has been added.
			CPPUNIT_ASSERT( v.getNumEdges() == 1 );
			CPPUNIT_ASSERT( v.getEdge(0).getWeight() == 1 );
			CPPUNIT_ASSERT( v.getEdge(0).getStartVertex() == 1 );
			CPPUNIT_ASSERT( v.getEdge(0).getEndVertex() == 2 );
		}

		void testChangeVertexEdge()
		{//Basic test of chanign a vertex's edge.
			//Set up the vertex and the edge.
			Graph::Edge ed(1, 1, 2);
			Graph::Vertex<int> v(1, 2);
			
			//Verify the vertex has no edges yet.
			CPPUNIT_ASSERT( v.getNumEdges() == 0 );

			//Add the edge.
			v.addEdge( ed );
			
			//Verfiy the edge has been added.
			CPPUNIT_ASSERT( v.getNumEdges() == 1 );
			CPPUNIT_ASSERT( v.getEdge(0).getWeight() == 1 );

			//Change the edge.
			v.getEdge(0).setWeight(2);
			//v.changeEdgeWeight( 0, 2 );
			
			//Verfiy the edge has been changed.
			CPPUNIT_ASSERT( v.getNumEdges() == 1 );
			CPPUNIT_ASSERT( v.getEdge(0).getWeight() == 2 );
			CPPUNIT_ASSERT( v.getEdge(0).getStartVertex() == 1 );
			CPPUNIT_ASSERT( v.getEdge(0).getEndVertex() == 2 );
		}

		void testClearVertexEdges()
		{//Basic test of clearing a vertex's edge.
			//Set up the vertex and the edge.
			Graph::Edge ed1(1, 1, 2);
			Graph::Edge ed2(2, 1, 2);
			Graph::Vertex<int> v(1, 2);
			
			//Verify the vertex has no edges yet.
			CPPUNIT_ASSERT( v.getNumEdges() == 0 );

			//Add the edges.
			v.addEdge( ed1 );
			v.addEdge( ed2 );
			
			//Verfiy the edge has been added.
			CPPUNIT_ASSERT( v.getNumEdges() == 2 );
			CPPUNIT_ASSERT( v.getEdge(0).getWeight() == 1 );
			CPPUNIT_ASSERT( v.getEdge(1).getWeight() == 2 );

			//Clear the edges.
			v.clearEdges();
			
			//Verfiy the edges have been cleared.
			CPPUNIT_ASSERT( v.getNumEdges() == 0 );
		}
		
		//Create the test suite using CPPUnit macros.
		CPPUNIT_TEST_SUITE( VertexTest );
		CPPUNIT_TEST( testCreateVertex );
		CPPUNIT_TEST( testChangeVertex );
		CPPUNIT_TEST( testVertexWithEdge );
		CPPUNIT_TEST( testChangeVertexEdge );
		CPPUNIT_TEST( testClearVertexEdges );
		CPPUNIT_TEST_SUITE_END( );
};

int main()
{
	CPPUNIT_TEST_SUITE_REGISTRATION( VertexTest );
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
