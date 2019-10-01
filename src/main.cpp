#include <iterator> // begin(), end()
#include <functional>

#include "gtest/gtest.h"
#include "../include/graal.h"

#define which_lib graal // uncomment this if you wanna run the graal library
//#define which_lib std // uncomment this if you wanna run the std library.

//== MinMax

TEST(MinMax, UniqueValuesSorted)
{
    int A[]{ 1, 2, 3, 4, 5 };

    //const auto [ min, max ] = which_lib::minmax( std::begin(A), std::end(A), std::less< int >() );
    auto result = which_lib::minmax( std::begin(A), std::end(A), std::less< int >() );
    auto min = result.first;
    auto max = result.second;

    ASSERT_NE( min, nullptr );
    EXPECT_EQ( min, std::begin(A) );
    EXPECT_EQ( *min, 1 );

    ASSERT_NE( max, nullptr );
    EXPECT_EQ( max, std::prev(std::end(A)) );
    EXPECT_EQ( *max, 5 );
}

TEST(MinMax, UniqueValuesReverseSorted)
{
    int A[]{ 5, 4, 3, 2, 1 };

    //const auto [ min, max ] = which_lib::minmax( std::begin(A), std::end(A), std::less< int >() );
    auto result = which_lib::minmax( std::begin(A), std::end(A), std::less< int >() );
    auto min = result.first;
    auto max = result.second;

    ASSERT_NE( min, nullptr );
    EXPECT_EQ( min, std::prev(std::end(A)) );
    EXPECT_EQ( *min, 1 );

    ASSERT_NE( max, nullptr );
    EXPECT_EQ( max, std::begin(A) );
    EXPECT_EQ( *max, 5 );
}

TEST(MinMax, AllEqual)
{
    int A[]{ 1, 1, 1, 1, 1 };

    //const auto [ min, max ] = which_lib::minmax( std::begin(A), std::end(A), std::less< int >() );
    auto result = which_lib::minmax( std::begin(A), std::end(A), std::less< int >() );
    auto min = result.first;
    auto max = result.second;
    ASSERT_NE( min, nullptr );
    EXPECT_EQ( min, std::begin(A) );
    EXPECT_EQ( *min, 1 );

    ASSERT_NE( max, nullptr );
    EXPECT_EQ( max, std::prev(std::end(A)) );
    EXPECT_EQ( *max, 1 );
}

TEST(MinMax, UniqueValuesRandomOrder )
{
    int A[]{ 2, 3, 5, 4, 1 };

    //const auto [ min, max ] = which_lib::minmax( std::begin(A), std::end(A), std::less< int >() );
    //const auto [ emin, emax ] = std::minmax_element( std::begin(A), std::end(A) );
    auto result = which_lib::minmax( std::begin(A), std::end(A), std::less< int >() );
    auto min = result.first;
    auto max = result.second;
    auto eresult = std::minmax_element( std::begin(A), std::end(A) );
    auto emin = eresult.first;
    auto emax = eresult.second;

    ASSERT_NE( min, nullptr );
    EXPECT_EQ( min, emin );
    EXPECT_EQ( *min, 1 );

    ASSERT_NE( max, nullptr );
    EXPECT_EQ( max, emax );
    EXPECT_EQ( *max, 5 );
}

TEST(MinMax, RepeatedValuesRandomOrder )
{
    int A[]{ 2, 3, 2, 5, 1, 4, 5, 4, 1 };

    //const auto [ min, max ] = which_lib::minmax( std::begin(A), std::end(A), std::less< int >() );
    //const auto [ emin, emax ] = std::minmax_element( std::begin(A), std::end(A) );
    auto result = which_lib::minmax( std::begin(A), std::end(A), std::less< int >() );
    auto min = result.first;
    auto max = result.second;
    auto eresult = std::minmax_element( std::begin(A), std::end(A) );
    auto emin = eresult.first;
    auto emax = eresult.second;
    ASSERT_NE( min, nullptr );
    EXPECT_EQ( min, emin );
    EXPECT_EQ( *min, 1 );

    ASSERT_NE( max, nullptr );
    EXPECT_EQ( max, emax );
    EXPECT_EQ( *max, 5 );
}

TEST(MinMax, EmptyList )
{
    int A[]{ 1 };

    //const auto [ min, max ] = which_lib::minmax( std::begin(A), std::begin(A), std::less< int >() );
    //const auto [ emin, emax ] = std::minmax_element( std::begin(A), std::begin(A) );
    auto result = which_lib::minmax( std::begin(A), std::begin(A), std::less< int >() );
    auto min = result.first;
    auto max = result.second;
    auto eresult = std::minmax_element( std::begin(A), std::begin(A) );
    auto emin = eresult.first;
    auto emax = eresult.second;

    ASSERT_NE( min, nullptr );
    EXPECT_EQ( min, emin );
    EXPECT_EQ( *min, 1 );

    ASSERT_NE( max, nullptr );
    EXPECT_EQ( max, emax );
    EXPECT_EQ( *max, 1 );
}

TEST(MinMax, SingleElement )
{
    int A[]{ 1 };

    //const auto [ min, max ] = which_lib::minmax( std::begin(A), std::end(A), std::less< int >() );
    //const auto [ emin, emax ] = std::minmax_element( std::begin(A), std::end(A) );
    auto result = which_lib::minmax( std::begin(A), std::end(A), std::less< int >() );
    auto min = result.first;
    auto max = result.second;
    auto eresult = std::minmax_element( std::begin(A), std::end(A) );
    auto emin = eresult.first;
    auto emax = eresult.second;

    ASSERT_NE( min, nullptr );
    EXPECT_EQ( min, emin );
    EXPECT_EQ( *min, 1 );

    ASSERT_NE( max, nullptr );
    EXPECT_EQ( max, emax );
    EXPECT_EQ( *max, 1 );
}

//== Reverse

TEST(Reverse, ReverseEntireArrayEven)
{
    int A[]{ 1, 2, 3, 4, 5, 6 };
    int result[]{ 6, 5, 4, 3, 2, 1 };

    which_lib::reverse( std::begin(A), std::end(A) );

    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(result) ) );
}

TEST(Reverse, ReverseEntireArrayOdd)
{
    int A[]{ 1, 2, 3, 4, 5 };
    int A_E[]{ 5, 4, 3, 2, 1 };

    which_lib::reverse( std::begin(A), std::end(A) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(Reverse, ReversePartOfArrayEven)
{
    int A[]  { 1, 2, 3, 4, 5, 6, 7 };
    int A_E[]{ 1, 2, 6, 5, 4, 3, 7 };

    which_lib::reverse( std::begin(A)+2, std::begin(A)+6 );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(Reverse, ReversePartOfArrayOdd)
{
    int A[]{ 1, 2, 3, 4, 5, 6, 7 };
    int A_E[]{ 1, 6, 5, 4, 3, 2, 7 };

    which_lib::reverse( std::begin(A)+1, std::begin(A)+6 );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

//== Copy

TEST(Copy, CopyEntireArray)
{
    int A[]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
    int A_E[]{ 'a', 'a', 'a', 'a', 'a', 'a', 'a' };

    which_lib::copy( std::begin(A), std::end(A), std::begin(A_E) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(Copy, CopyPartOfArray)
{
    int A[]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
    int A_E[]{ 'a', 'b', 'a', 'a', 'a', 'a', 'a' };

    which_lib::copy( std::begin(A)+2, std::end(A), std::begin(A_E)+2 );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(Copy, CopyFinalPartOfArray)
{
    int A[]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
    int A_E[]{ 'a', 'b', 'c', 'd', 'e', 'b', 'a' };

    which_lib::copy( std::begin(A)+5, std::end(A), std::begin(A_E)+5 );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(Copy, CopySingleElementArray)
{
    int A[]{ 'a' };
    int A_E[]{ 'x' };

    which_lib::copy( std::begin(A), std::end(A), std::begin(A_E) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

//== fund_if()

TEST(FindIf, SeveralAreTrue)
{
	int A[]{ 1, 6, 3, 6, 5, 2, 6 };
	auto result = which_lib::find_if( std::begin(A), std::end(A),
            []( int e )->bool{ return e > 5 ; } );
	ASSERT_EQ( std::begin(A)+1, result );
}

TEST(FindIf, NoneIsTrue)
{
	int A[]{ 1, 2, 3, 4, 5 };
	auto result = which_lib::find_if( std::begin(A), std::end(A),
            []( int e )->bool{ return e > 5 ; } );
	ASSERT_EQ( std::end(A), result );
}

TEST(FindIf, AllAreTrue)
{
	int A[]{ 6, 7, 8, 9, 10 };
	auto result = which_lib::find_if( std::begin(A), std::end(A),
            []( int e )->bool{ return e > 5 ; } );
	ASSERT_EQ( std::begin(A), result );
}

TEST(FindIf, PredicateTrueAtBeginning)
{
	int A[]{ 6, 2, 3, 4, 5, 2, 1 };
	auto result = which_lib::find_if( std::begin(A), std::end(A),
            []( int e )->bool{ return e > 5 ; } );
	ASSERT_EQ( std::begin(A), result );
}

TEST(FindIf, PredicateTrueAtMiddle)
{
	int A[]{ 1, 2, 3, 6, 5, 2, 1 };
	auto result = which_lib::find_if( std::begin(A), std::end(A),
            []( int e )->bool{ return e > 5 ; } );
	ASSERT_EQ( std::begin(A)+3, result );
}

TEST(FindIf, PredicateTrueAtEnd)
{
	int A[]{ 1, 2, 3, 4, 5, 2, 6 };
	auto result = which_lib::find_if( std::begin(A), std::end(A),
            []( int e )->bool{ return e > 5 ; } );
	ASSERT_EQ( std::prev(std::end(A)), result );
}

//== find()

TEST(Find, NoneIsEqual)
{
	int A[]{ 'k', 'a', 'b', 'l', 'q' };
	int target{ 'x' };
	auto result = which_lib::find( std::begin(A), std::end(A), target,
                            []( int a, int b )->bool{ return a == b; } );
	ASSERT_EQ( std::end(A), result );
}

TEST(Find, AllAreEqual)
{
	int A[]{ 'x', 'x', 'x', 'x', 'x' };
	int target{ 'x' };
	auto result = which_lib::find( std::begin(A), std::end(A), target,
                            []( int a, int b )->bool{ return a == b; } );
	ASSERT_EQ( std::begin(A), result );
}

TEST(Find, SeveralAreEqual)
{
	int A[]{ 'a', 'x', 'b', 'x', 'c' };
	int target{ 'x' };
	auto result = which_lib::find( std::begin(A), std::end(A), target,
                            []( int a, int b )->bool{ return a == b; } );
	ASSERT_EQ( std::begin(A)+1, result );
}

TEST(Find, SingleEqualAtBeginning)
{
	int A[]{ 'x', 'a', 'q', 'l', 'k' };
	int target{ 'x' };
	auto result = which_lib::find( std::begin(A), std::end(A), target,
                            []( int a, int b )->bool{ return a == b; } );
	ASSERT_EQ( std::begin(A), result );
}

TEST(Find, SingleEqualAtEnd)
{
	int A[]{ 'k', 'a', 'q', 'l', 'x' };
	int target{ 'x' };
	auto result = which_lib::find( std::begin(A), std::end(A), target,
                            []( int a, int b )->bool{ return a == b; } );
	ASSERT_EQ( std::prev(std::end(A)), result );
}

TEST(Find, SingleEqualInMiddle)
{
	int A[]{ 'k', 'a', 'x', 'l', 'q' };
	int target{ 'x' };
	auto result = which_lib::find( std::begin(A), std::end(A), target,
                            []( int a, int b )->bool{ return a == b; } );
	ASSERT_EQ( std::begin(A)+2, result );
}

//== all_of

TEST(AllOf, AllAreOk)
{
    int A[]{ 10, 20, 30, 40, 50, 60, 70 };
    bool result;

    result = which_lib::all_of( std::begin(A), std::end(A),
            []( const int& e ){ return e > 0; } );
							
    ASSERT_TRUE( result );
}

TEST(AllOf, AllAreNotOk)
{
    int A[]{ 10, 20, 30, 40, 50, 60, 70 };
    bool result;

    result = which_lib::all_of( std::begin(A), std::end(A),
            []( const int& e ){ return e < 0; } );
							
    ASSERT_FALSE( result );
}

TEST(AllOf, FewAreOk)
{
    int A[]{ 10, 20, 30, 40, 50, 60, 70 };
    bool result;

    result = which_lib::all_of( std::begin(A), std::end(A),
            []( const int& e ){ return e > 30; } );
							
    ASSERT_FALSE( result );
}

TEST(AllOf, EmptyInput)
{
    int A[]{ 10, 20, 30, 40, 50, 60, 70 };
    bool result;

    result = which_lib::all_of( std::begin(A), std::begin(A),
            []( const int& e ){ return e > 30; } );
							
    ASSERT_TRUE( result );
}

//== any_of

TEST(AnyOf, AllAreOk)
{
    int A[]{ 10, 20, 30, 40, 50, 60, 70 };
    bool result;

    result = which_lib::any_of( std::begin(A), std::end(A),
            []( const int& e ){ return e > 0; } );
							
    ASSERT_TRUE( result );
}

TEST(AnyOf, AllAreNotOk)
{
    int A[]{ 10, 20, 30, 40, 50, 60, 70 };
    bool result;

    result = which_lib::any_of( std::begin(A), std::end(A),
            []( const int& e ){ return e < 0; } );
							
    ASSERT_FALSE( result );
}

TEST(AnyOf, FewAreOk)
{
    int A[]{ 10, 20, 30, 40, 50, 60, 70 };
    bool result;

    result = which_lib::any_of( std::begin(A), std::end(A),
            []( const int& e ){ return e > 30; } );
							
    ASSERT_TRUE( result );
}

TEST(AnyOf, EmptyInput)
{
    int A[]{ 10, 20, 30, 40, 50, 60, 70 };
    bool result;

    result = which_lib::any_of( std::begin(A), std::begin(A),
            []( const int& e ){ return e > 30; } );
							
    ASSERT_FALSE( result );
}

//== none_of

TEST(NoneOf, AllAreOk)
{
    int A[]{ 10, 20, 30, 40, 50, 60, 70 };
    bool result;

    result = which_lib::none_of( std::begin(A), std::end(A),
            []( const int& e ){ return e > 0; } );
							
    ASSERT_FALSE( result );
}

TEST(NoneOf, AllAreNotOk)
{
    int A[]{ 10, 20, 30, 40, 50, 60, 70 };
    bool result;

    result = which_lib::none_of( std::begin(A), std::end(A),
            []( const int& e ){ return e < 0; } );
							
    ASSERT_TRUE( result );
}

TEST(NoneOf, FewAreOk)
{
    int A[]{ 10, 20, 30, 40, 50, 60, 70 };
    bool result;

    result = which_lib::none_of( std::begin(A), std::end(A),
            []( const int& e ){ return e > 30; } );
							
    ASSERT_FALSE( result );
}

TEST(NoneOf, EmptyInput)
{
    int A[]{ 10, 20, 30, 40, 50, 60, 70 };
    bool result;

    result = which_lib::none_of( std::begin(A), std::begin(A),
            []( const int& e ){ return e > 30; } );
							
    ASSERT_TRUE( result );
}

//=== equal, version #1
TEST(Equal, AllAreEqualSameSize)
{
	int A[]{ 'a', 'b', 'c', 'd' };
	int A_E[]{ 'a', 'b', 'c', 'd' };

	bool result;
	result = which_lib::equal( std::begin(A), std::end(A),
						       std::begin(A_E),
                               []( int a, int b )->bool { return a==b; } );
	ASSERT_TRUE( result );
}

TEST(Equal, AllAreNotEqualSameSize)
{
	int A[]{ 'a', 'b', 'c', 'd' };
	int A_E[]{ 'x', 'y', 'z', 'w' };

	bool result;
	result = which_lib::equal( std::begin(A), std::end(A),
						       std::begin(A_E),
                               []( int a, int b )->bool { return a==b; } );
	ASSERT_FALSE( result );
}

TEST(Equal, PartAreEqualSameSize)
{
	int A[]{ 'a', 'b', 'c', 'd' };
	int A_E[]{ 'x', 'y', 'c', 'd' };

	bool result;
	result = which_lib::equal( std::begin(A), std::end(A),
						       std::begin(A_E),
                               []( int a, int b )->bool { return a==b; } );
	ASSERT_FALSE( result );
}

TEST(Equal2, AllAreEqual1stGreater2nd)
{
	int A[]{ 'a', 'b', 'c', 'd', 'e', 'f' };
	int A_E[]{ 'a', 'b', 'c', 'd' };

	bool result;
	result = which_lib::equal( std::begin(A), std::end(A),
						       std::begin(A_E), std::end(A_E),
                               []( int a, int b )->bool { return a==b; } );
	ASSERT_FALSE( result );
}

TEST(Equal2, AllAreEqual1stGreater2ndCorrectRange)
{
	int A[]{ 'a', 'b', 'c', 'd', 'e', 'f' };
	int A_E[]{ 'a', 'b', 'c', 'd' };

	bool result;
	result = which_lib::equal( std::begin(A), std::begin(A)+std::distance(std::begin(A_E), std::end(A_E) ),
						       std::begin(A_E), std::end(A_E),
                               []( int a, int b )->bool { return a==b; } );
	ASSERT_TRUE( result );
}

TEST(Equal2, PartIsNotEqual)
{
	int A[]{ 'a', 'b', 'c', 'd', 'e', 'f' };
	int A_E[]{ 'x', 'y', 'a', 'b', 'c', 'd', 'h', 'i' };

	bool result;
	result = which_lib::equal( std::begin(A), std::end(A),
						       std::begin(A_E)+2, std::end(A_E)+6,
                               []( int a, int b )->bool { return a==b; } );
	ASSERT_FALSE( result );
}

TEST(Equal2, PartIsEqual)
{
	int A[]{ 'a', 'b', 'c', 'd'  };
	int A_E[]{ 'x', 'y', 'a', 'b', 'c', 'd', 'h', 'i' };

	bool result;
	result = which_lib::equal( std::begin(A), std::end(A),
						       std::begin(A_E)+2, std::begin(A_E)+6,
                               []( int a, int b )->bool { return a==b; } );
	ASSERT_TRUE( result );
}

//== unique()
TEST(Unique, SomeRepetitions)
{
    int A[]{ 1, 2, 3, 4, 5, 5, 4, 4, 4, 3, 2, 3, 2, 1 };
    int A_E[]{ 1, 2, 3, 4, 5 };

    auto result = which_lib::unique( std::begin(A), std::end(A),
                        []( const int& a, const int& b )->bool{ return a == b; } );

    ASSERT_TRUE( std::equal( std::begin(A), result, std::begin(A_E) ));
}

TEST(Unique, AllEquals)
{
    int A[]{ 1, 1, 1, 1, 1, 1, 1 };
    int A_E[]{ 1 };

    auto result = which_lib::unique( std::begin(A), std::end(A),
                        []( const int& a, const int& b )->bool{ return a == b; } );

    ASSERT_TRUE( std::equal( std::begin(A), result, std::begin(A_E) ));
}

TEST(Unique, AllAreUnique)
{
    int A[]{ 1, 2, 3, 4, 5, 6, 7 };
    int A_E[]{ 1, 2, 3, 4, 5, 6, 7 };

    auto result = which_lib::unique( std::begin(A), std::end(A),
                        []( const int& a, const int& b )->bool{ return a == b; } );

    ASSERT_TRUE( std::equal( std::begin(A), result, std::begin(A_E) ));
}

TEST(Unique, MirrorUnique)
{
    int A[]{ 1, 2, 3, 4, 5, 5, 4, 3, 2, 1 };
    int A_E[]{ 1, 2, 3, 4, 5 };

    auto result = which_lib::unique( std::begin(A), std::end(A),
                        []( const int& a, const int& b )->bool{ return a == b; } );

    ASSERT_TRUE( std::equal( std::begin(A), result, std::begin(A_E) ));
}

//== partition()
TEST(Partition, AllAreTrue)
{
	int A[]{ 6, 7, 8, 9, 10 };
	int A_E[]{ 6, 7, 8, 9, 10 };

    auto predicate = []( const int& e )->bool{ return e > 5; };

	auto result = which_lib::partition( std::begin(A), std::end(A), predicate );

    // Location of the pointer must be correct.
    ASSERT_EQ( result , std::end(A) );
    // Uset STL function to test whether the partion worked.
	ASSERT_TRUE( std::is_partitioned( std::begin(A), std::begin(A), predicate ) );
    // Let us see if the elements have been preserved.
    std::sort(std::begin(A), std::end(A));
    std::vector<int> v_intersection;
    std::set_intersection( std::begin(A), std::end(A),
                           std::begin(A_E), std::end(A_E),
                           std::back_inserter(v_intersection));
    ASSERT_EQ( std::distance(std::begin(A), std::end(A) ), v_intersection.size() );
}

TEST(Partition, NoneAreTrue)
{
	int A[]{ 0, 1, 2, 3, 4 };
	int A_E[]{ 0, 1, 2, 3, 4 };

    auto predicate = []( const int& e )->bool{ return e > 5; };

	auto result = which_lib::partition( std::begin(A), std::end(A), predicate );

    // Location of the pointer must be correct.
    ASSERT_EQ( std::distance( std::begin(A), result ), 0 );
    // Uset STL function to test whether the partion worked.
	ASSERT_TRUE( std::is_partitioned( std::begin(A), std::begin(A), predicate ) );
    ASSERT_EQ( result, std::begin(A) );
    // Let us see if the elements have been preserved.
    std::sort(std::begin(A), std::end(A));
    std::vector<int> v_intersection;
    std::set_intersection( std::begin(A), std::end(A),
                           std::begin(A_E), std::end(A_E),
                           std::back_inserter(v_intersection));
    ASSERT_EQ( std::distance(std::begin(A), std::end(A) ), v_intersection.size() );
}

TEST(Partition, SomeAreTrueInverted)
{
	int A[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int A_E[]{ 6, 7, 8, 9, 10, 1, 2, 3, 4, 5 };
    // Lambda
    auto predicate = []( const int& e )->bool{ return e > 5; };

	auto result = which_lib::partition( std::begin(A), std::end(A), predicate );
    ASSERT_EQ( std::distance( std::begin(A), result ), 5 );
    // Uset STL function to test whether the partion worked.
	ASSERT_TRUE( std::is_partitioned( std::begin(A), std::begin(A), predicate ) );
    // Let us see if the elements have been preserved.
    std::sort(std::begin(A), std::end(A));
    std::sort(std::begin(A_E), std::end(A_E));
    std::vector<int> v_intersection;
    std::set_intersection( std::begin(A), std::end(A),
                           std::begin(A_E), std::end(A_E),
                           std::back_inserter(v_intersection));
    ASSERT_EQ( std::distance(std::begin(A), std::end(A) ), v_intersection.size() );
}

TEST(Partition, SomeAreTrueInterleaved)
{
	int A[]{ 1, 10, 2, 9, 3, 8, 4, 7, 5, 6 };
	int A_E[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    auto predicate = []( const int& e )->bool{ return e > 5; };

	auto result = which_lib::partition( std::begin(A), std::end(A), predicate );
    ASSERT_EQ( std::distance( std::begin(A), result ), 5 );
    // Uset STL function to test whether the partion worked.
	ASSERT_TRUE( std::is_partitioned( std::begin(A), std::begin(A), predicate ) );
    // Let us see if the elements have been preserved.
    std::sort(std::begin(A), std::end(A));
    std::vector<int> v_intersection;
    std::set_intersection( std::begin(A), std::end(A),
                           std::begin(A_E), std::end(A_E),
                           std::back_inserter(v_intersection));
    ASSERT_EQ( std::distance(std::begin(A), std::end(A) ), v_intersection.size() );
}


//== sort()

TEST(Sort, BasicUniqueElements)
{
    int A[]{ 2, 5, 3, 6, 1, 30, 10 };
    int A_O[]{ 1, 2, 3, 5, 6, 10, 30 };

    which_lib::sort( std::begin(A), std::end(A),
            [](const int&a, const int& b){ return a<b; } );

    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_O) ) );
}

TEST(Sort, BasicDuplicateElements)
{
    int A[]{ 7, 6, 5, 4, 1, 1, 1 };
    int A_O[]{ 1, 1, 1, 4, 5, 6, 7 };

    which_lib::sort( std::begin(A), std::end(A),
            [](const int&a, const int& b){ return a<b; } );

    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_O) ) );
}

TEST(Sort, AlreadySorted)
{
    int A[]{ 1, 2, 3, 4, 5, 6, 7 };
    int A_O[]{ 1, 2, 3, 4, 5, 6, 7 };

    which_lib::sort( std::begin(A), std::end(A),
            [](const int&a, const int& b){ return a<b; } );

    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_O) ) );
}

TEST(Sort, ReverseSorted)
{
    int A[]{ 7, 6, 5, 4, 3, 2, 1 };
    int A_O[]{ 1, 2, 3, 4, 5, 6, 7 };

    which_lib::sort( std::begin(A), std::end(A),
            [](const int&a, const int& b){ return a<b; } );

    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_O) ) );
}

TEST(Rotate, Incremental)
{
    int A[]{ 1, 2, 3, 4, 5, 6, 7 };
    int A_bakup[]{ 1, 2, 3, 4, 5, 6, 7 };
    int A_E[][7]{
        { 2, 3, 4, 5, 6, 7, 1 },
        { 3, 4, 5, 6, 7, 1, 2 },
        { 4, 5, 6, 7, 1, 2, 3 },
        { 5, 6, 7, 1, 2, 3, 4 },
        { 6, 7, 1, 2, 3, 4, 5 },
        { 7, 1, 2, 3, 4, 5, 6 },
        { 1, 2, 3, 4, 5, 6, 7 } };

    for ( int i{0} ; i < std::distance(std::begin(A), std::end(A))-1 ; ++i )
    {
        which_lib::rotate( std::begin(A), std::begin(A)+(i+1), std::end(A) );
        ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E[i]) ) );
        // Reset back to the original values of array A.
        std::copy( std::begin(A_bakup), std::end(A_bakup), std::begin(A) );
    }
}

TEST(Rotate, Block)
{
    int A[]{ 1, 2, 3, 4, 5, 6, 7 };
    int A_E[]{ 5, 6, 7, 1, 2, 3, 4 };

    which_lib::rotate( std::begin(A), std::begin(A)+4, std::end(A) );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );

}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
