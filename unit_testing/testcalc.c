#include "Unity/src/unity.h"
#include "person.h"
#include <string.h>

// Test setup
void setUp(void) {
    // This is run before each test case.
}

// Test teardown
void tearDown(void) {
    // This is run after each test case.
}

// Test case: Search for a person's town when the person exists
void test_searchTown_shouldReturnTownWhenPersonExists(void) {
    struct Person persons[3] = {
        {"babu", "ahamedabad"},
        {"suri", "india"},
        {"raki", "anantapur"}
    };
    struct Person searchPerson;
    strcpy(searchPerson.name, "raki");

    searchTown(persons, 3, &searchPerson);

    TEST_ASSERT_EQUAL_STRING("anantapur", searchPerson.town);
}

// Test case: Search for a person's town when the person does not exist
void test_searchTown_shouldReturnEmptyStringWhenPersonDoesNotExist(void) {
    struct Person persons[3] = {
        {"babu", "hyderabad"},
        {"suri", "bangalore"},
        {"raki", "chennai"}
    };
    struct Person searchPerson;
    strcpy(searchPerson.name, "bob");

    searchTown(persons, 3, &searchPerson);

    TEST_ASSERT_EQUAL_STRING("", searchPerson.town);  // Expecting an empty string
}

int main(void) {
    UNITY_BEGIN();

    // Run all the test cases
    RUN_TEST(test_searchTown_shouldReturnTownWhenPersonExists);
    RUN_TEST(test_searchTown_shouldReturnEmptyStringWhenPersonDoesNotExist);

    return UNITY_END();
}

