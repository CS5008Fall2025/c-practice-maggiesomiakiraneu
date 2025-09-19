/**
 * Student Name: Maggie Li
 * Semester: Fall 2025
 * 
 * 
 * This file is to test the functions in cpractice.h. You are to write at least *TWO* (maybe more) tests for every function. 
 * Some sample ones have been provided for you.
*/

#include <stdio.h>  // basic input and output
#include <stdlib.h> // standard library
#include <math.h>  //need this for my helper functions

#include "cpractice.h" // header file for cpractice.c


// this may help with some tests, as the array numbers match their index
int * create_simple_array(int size) {
    int * arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

// creating a helper
int arrays_equal(int *arr1, int *arr2, int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

// creating a helper 
int double_equals(double a, double b, double epsilon) {
    return fabs(a - b) < epsilon;
}


/**
 * Tests a basic swap
*/
int test_swap_one() {
    printf("1. test_swap_one()\n");
    int a = 5;
    int b = 10;
    swap(&a, &b);
    if (a == 10 && b == 5) {
        return 1;
    }
    return 0;
}

/**
 * Tests swap with negative numbers
*/
int test_swap_negative() {
    printf("2. test_swap_negative()\n");
    int a = -5;
    int b = 15;
    swap(&a, &b);
    if (a == 15 && b == -5) {
        return 1;
    }
    return 0;
}

/**
 * Tests the create_array_of_ints_fib function
*/
int test_create_array_of_ints_fib() {
    printf("3. test_create_array_of_ints_fib()\n");
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr);
    // everything matched
    return 1;
}

/**
 * Tests fibonacci with edge cases
*/
int test_create_array_of_ints_fib_edge_cases() {
    printf("4. test_create_array_of_ints_fib_edge_cases()\n");
   
    int* arr1 = create_array_of_ints_fib(1);
    if (arr1 == NULL || arr1[0] != 1) {
        if (arr1) free(arr1);
        return 0;
    }
    free(arr1);
   
    int* arr0 = create_array_of_ints_fib(0);
    if (arr0 != NULL) {
        return 0;
    }
    
    int* arr_neg = create_array_of_ints_fib(-5);
    if (arr_neg != NULL) {
        return 0;
    }
    
    return 1;
}

/**
 * Tests reverse array with odd length
*/
int test_reverse_array_odd() {
    printf("5. test_reverse_array_odd()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int expected[] = {5, 4, 3, 2, 1};
    reverse_array(arr, 5);
    
    return arrays_equal(arr, expected, 5);
}

/**
 * Tests reverse array with even length
*/
int test_reverse_array_even() {
    printf("6. test_reverse_array_even()\n");
    int arr[] = {1, 2, 3, 4};
    int expected[] = {4, 3, 2, 1};
    reverse_array(arr, 4);
    
    return arrays_equal(arr, expected, 4);
}

/**
 * Tests double array size basic functionality
*/
int test_double_array_size_basic() {
    printf("7. test_double_array_size_basic()\n");
    int original[] = {1, 2, 3};
    int* doubled = double_array_size(original, 3);
    
    if (doubled == NULL) return 0;
    
    for (int i = 0; i < 3; i++) {
        if (doubled[i] != original[i]) {
            free(doubled);
            return 0;
        }
    }
    
    for (int i = 3; i < 6; i++) {
        if (doubled[i] != 0) {
            free(doubled);
            return 0;
        }
    }
    
    free(doubled);
    return 1;
}

/**
 * Tests double array size with empty array
*/
int test_double_array_size_empty() {
    printf("8. test_double_array_size_empty()\n");
    int* doubled = double_array_size(NULL, 0);
    
    if (doubled == NULL) return 0;
    
    free(doubled);
    return 1;
}

/**
 * Tests copy array normal case (start <= end)
*/
int test_copy_array_normal() {
    printf("9. test_copy_array_normal()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int new_size;
    int* copied = copy_array_start_end_loop(arr, 5, 1, 3, &new_size);
    
    if (copied == NULL || new_size != 3) {
        if (copied) free(copied);
        return 0;
    }
    
    int expected[] = {2, 3, 4};
    int result = arrays_equal(copied, expected, 3);
    free(copied);
    return result;
}

/**
 * Tests copy array wrap around case (start > end)
*/
int test_copy_array_wrap() {
    printf("10. test_copy_array_wrap()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int new_size;
    int* copied = copy_array_start_end_loop(arr, 5, 3, 1, &new_size);
    
    if (copied == NULL || new_size != 4) {
        if (copied) free(copied);
        return 0;
    }
    
    int expected[] = {4, 5, 1, 2};
    int result = arrays_equal(copied, expected, 4);
    free(copied);
    return result;
}

/**
 * Tests copy array with invalid indices
*/
int test_copy_array_invalid() {
    printf("11. test_copy_array_invalid()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int new_size;
    
    int* copied1 = copy_array_start_end_loop(arr, 5, -1, 3, &new_size);
    if (copied1 != NULL) return 0;
    
    int* copied2 = copy_array_start_end_loop(arr, 5, 5, 3, &new_size);
    if (copied2 != NULL) return 0;
    
    return 1;
}

/**
 * Tests create point basic functionality
*/
int test_create_point_basic() {
    printf("12. test_create_point_basic()\n");
    Point* p = create_point(5, 10);
    
    if (p == NULL || p->x != 5 || p->y != 10) {
        if (p) free(p);
        return 0;
    }
    
    free(p);
    return 1;
}

/**
 * Tests create point with negative coordinates
*/
int test_create_point_negative() {
    printf("13. test_create_point_negative()\n");
    Point* p = create_point(-5, -10);
    
    if (p == NULL || p->x != -5 || p->y != -10) {
        if (p) free(p);
        return 0;
    }
    
    free(p);
    return 1;
}

/**
 * Tests create polygon basic functionality
*/
int test_create_polygon_basic() {
    printf("14. test_create_polygon_basic()\n");
    Polygon* poly = create_polygon(3);
    
    if (poly == NULL || poly->size != 3 || poly->points == NULL) {
        if (poly) free_polygon(poly);
        return 0;
    }
    
    free_polygon(poly);
    return 1;
}

/**
 * Tests create polygon with zero size
*/
int test_create_polygon_zero() {
    printf("15. test_create_polygon_zero()\n");
    Polygon* poly = create_polygon(0);
    
    if (poly == NULL || poly->size != 0) {
        if (poly) free_polygon(poly);
        return 0;
    }
    
    free_polygon(poly);
    return 1;
}

/**
 * Tests create rectangle
*/
int test_create_rectangle() {
    printf("16. test_create_rectangle()\n");
    Polygon* rect = create_rectangle(5, 10);
    
    if (rect == NULL || rect->size != 4) {
        if (rect) free_polygon(rect);
        return 0;
    }
    
    if (rect->points[0]->x != 0 || rect->points[0]->y != 0 ||
        rect->points[1]->x != 5 || rect->points[1]->y != 0 ||
        rect->points[2]->x != 5 || rect->points[2]->y != 10 ||
        rect->points[3]->x != 0 || rect->points[3]->y != 10) {
        free_polygon(rect);
        return 0;
    }
    
    free_polygon(rect);
    return 1;
}

/**
 * Tests create rectangle with zero dimensions
*/
int test_create_rectangle_zero() {
    printf("17. test_create_rectangle_zero()\n");
    Polygon* rect = create_rectangle(0, 0);
    
    if (rect == NULL || rect->size != 4) {
        if (rect) free_polygon(rect);
        return 0;
    }
    
    for (int i = 0; i < 4; i++) {
        if (rect->points[i]->x != 0 || rect->points[i]->y != 0) {
            free_polygon(rect);
            return 0;
        }
    }
    
    free_polygon(rect);
    return 1;
}

/**
 * Tests create triangle
*/
int test_create_triangle() {
    printf("18. test_create_triangle()\n");
    Polygon* tri = create_triangle(5, 10);
    
    if (tri == NULL || tri->size != 3) {
        if (tri) free_polygon(tri);
        return 0;
    }
    
    if (tri->points[0]->x != 0 || tri->points[0]->y != 0 ||
        tri->points[1]->x != 5 || tri->points[1]->y != 0 ||
        tri->points[2]->x != 5 || tri->points[2]->y != 10) {
        free_polygon(tri);
        return 0;
    }
    
    free_polygon(tri);
    return 1;
}

/**
 * Tests create triangle with unit dimensions
*/
int test_create_triangle_unit() {
    printf("19. test_create_triangle_unit()\n");
    Polygon* tri = create_triangle(1, 1);
    
    if (tri == NULL || tri->size != 3) {
        if (tri) free_polygon(tri);
        return 0;
    }
    
    if (tri->points[0]->x != 0 || tri->points[0]->y != 0 ||
        tri->points[1]->x != 1 || tri->points[1]->y != 0 ||
        tri->points[2]->x != 1 || tri->points[2]->y != 1) {
        free_polygon(tri);
        return 0;
    }
    
    free_polygon(tri);
    return 1;
}

/**
 * Tests polygon area calculation for rectangle
*/
int test_calculate_polygon_area_rectangle() {
    printf("20. test_calculate_polygon_area_rectangle()\n");
    Polygon* rect = create_rectangle(5, 10);
    
    if (rect == NULL) return 0;
    
    double area = calculate_polygon_area(rect);
    double expected = 50.0; // 5 * 10
    
    int result = double_equals(area, expected, 0.001);
    free_polygon(rect);
    return result;
}

/**
 * Tests polygon area calculation for triangle
*/
int test_calculate_polygon_area_triangle() {
    printf("21. test_calculate_polygon_area_triangle()\n");
    Polygon* tri = create_triangle(6, 8);
    
    if (tri == NULL) return 0;
    
    double area = calculate_polygon_area(tri);
    double expected = 24.0;
    
    int result = double_equals(area, expected, 0.001);
    free_polygon(tri);
    return result;
}

/**
 * Tests polygon area with invalid input
*/
int test_calculate_polygon_area_invalid() {
    printf("22. test_calculate_polygon_area_invalid()\n");
    
    double area1 = calculate_polygon_area(NULL);
    if (!double_equals(area1, 0.0, 0.001)) return 0;
    
    Polygon* poly = create_polygon(2);
    if (poly == NULL) return 0;
    
    double area2 = calculate_polygon_area(poly);
    int result = double_equals(area2, 0.0, 0.001);
    
    free_polygon(poly);
    return result;
}

// this is a list of all the unit tests
int (*unitTests[])() = {
        test_swap_one,
        test_swap_negative,
        test_create_array_of_ints_fib,
        test_create_array_of_ints_fib_edge_cases,
        test_reverse_array_odd,
        test_reverse_array_even,
        test_double_array_size_basic,
        test_double_array_size_empty,
        test_copy_array_normal,
        test_copy_array_wrap,
        test_copy_array_invalid,
        test_create_point_basic,
        test_create_point_negative,
        test_create_polygon_basic,
        test_create_polygon_zero,
        test_create_rectangle,
        test_create_rectangle_zero,
        test_create_triangle,
        test_create_triangle_unit,
        test_calculate_polygon_area_rectangle,
        test_calculate_polygon_area_triangle,
        test_calculate_polygon_area_invalid,
};

int main(int argc, char const *argv[])
{
    int numTests = sizeof(unitTests) / sizeof(unitTests[0]);
    int numPassed = 0;

    for (int i = 0; i < numTests; i++) {
        if (unitTests[i]()) {
            numPassed++;
        } else {
            printf("Test %d failed\n", i);
        }
    }

    printf("Passed %d out of %d tests\n", numPassed, numTests);
    return 0;
}


