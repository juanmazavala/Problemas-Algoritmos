def sort_string_array(arr):
    """
    Sorts an array of strings in alphabetical order.
    The algorithm should sort the array in-place, meaning no additional arrays should be created.
    
    :param arr: List[str] - List of strings to be sorted
    :return: None - The array is modified in-place
    """
    # Implement the sorting algorithm here
    abc = "abcdefghijklmnñopqrstuvwxyz"
    length_arr = len(arr)
    for index in range(length_arr-1):
        for index_2 in range(1, length_arr-index):
            if arr[index_2] < arr[index_2-1]:
                arr[index_2], arr[index_2-1] = arr[index_2-1], arr[index_2]
    return None

    pass

# Test Cases
def test_sort_string_array():
    test_cases = [
        (["pear", "apple", "banana"], ["apple", "banana", "pear"]),
        (["fox", "cat", "elephant", "dolphin"], ["cat", "dolphin", "elephant", "fox"]),
        (["python", "java", "c++", "ruby"], ["c++", "java", "python", "ruby"]),
        (["sun", "moon", "star"], ["moon", "star", "sun"]),
        (["a", "b", "c"], ["a", "b", "c"]),
        ([], []),
        (["one"], ["one"]),
        (["ccc", "aaa", "bbb"], ["aaa", "bbb", "ccc"]),
    ]
    
    for i, (input_array, expected) in enumerate(test_cases):
        sort_string_array(input_array)
        assert input_array == expected, f"FAILED on case {i + 1}: expected {expected}, but got {input_array}"
    print("All tests PASSED.")

# Run Tests
if __name__ == "__main__":
    test_sort_string_array()
