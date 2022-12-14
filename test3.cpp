/*
 * main.cpp
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "list.h"

TEST_CASE("testing insert_before", "[DoubleLinkedList]") {
	DoubleLinkedList<int> b1;
	b1.push_front(7); b1.push_front(6); b1.push_front(5);
	b1.push_front(4); b1.push_front(3); b1.push_front(2);

	SECTION ( "b1.insert_before(2, 1)" ) {
		b1.insert_before(2, 1);
		REQUIRE(b1.length() == 7);
		REQUIRE(b1.toString() == "[1, 2, 3, 4, 5, 6, 7]");
	}

	SECTION ( "b1.insert_before(5, 1)" ) {
		b1.insert_before(5, 1);
		REQUIRE(b1.length() == 7);
		REQUIRE(b1.toString() == "[2, 3, 4, 1, 5, 6, 7]");
	}

	SECTION ( "b1.insert_before(7, 1)" ) {
		b1.insert_before(7, 1);
		REQUIRE(b1.length() == 7);
		REQUIRE(b1.toString() == "[2, 3, 4, 5, 6, 1, 7]");
	}

	SECTION ( "b1.insert_before(100, 1)" ) {
		REQUIRE_THROWS_AS(b1.insert_before(100, 1), NoSuchElement);
	}
}
