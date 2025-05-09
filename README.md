# String-to-Integer-atoi---Leetcode

## Problem Description

In this problem, you need to implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer. The algorithm for the function should follow these steps:

1. **Whitespace**: Ignore any leading whitespace in the string.
2. **Sign**: Determine the sign by checking if the next character is a '-' or '+', assuming positivity if neither is present.
3. **Conversion**: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits are read, return 0.
4. **Rounding**: If the integer is out of the 32-bit signed integer range ([-2^31, 2^31 - 1]), round the integer to remain in the range. Specifically, integers less than -2^31 should be rounded to -2^31, and integers greater than 2^31 - 1 should be rounded to 2^31 - 1.
5. **Result**: Return the integer as the final result.

### Examples

#### Example 1:
- **Input**: `"1337c0d3"`
- **Output**: `1337`

#### Example 2:
- **Input**: `"0-1"`
- **Output**: `0`

#### Example 3:
- **Input**: `"words and 987"`
- **Output**: `0`


## Explanation of my Code

- **Skipping Whitespace**: The code starts by skipping any leading whitespace or control characters (such as tabs and newlines). This is done using the condition:

    ```c
   	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
    ```

    This ensures that any spaces or control characters are ignored before processing the actual number.

- **Checking for Sign**: The function then checks if the number is negative or positive by looking for the presence of `'-'` or `'+'` signs. If the number is negative, the variable `s` is multiplied by `-1` to adjust the final result's sign.

    ```c
    if (s[i] == '-')
			c = c * -1;
    ```

    If both signs (`+` and `-`) are encountered consecutively, the function returns `0` because such input is considered invalid.

    ```c
    if ((s[i] == '-' && s[i+1] == '+') || 
        (s[i] == '+' && s[i+1] == '-') || 
        (s[i] == '-' && s[i+1] == '-') || 
        (s[i] == '+' && s[i+1] == '+'))
        return 0;
    ```

- **Reading Digits**: After the sign is processed, the code begins reading the digits of the number. It checks each character in the string to see if it is a digit (between `'0'` and `'9'`).

    ```c
    while (s[i] >= '0' && s[i] <= '9')
    ```

    For each digit, it converts the character to an integer and adds it to the variable `d`. The variable `d` is multiplied by 10 to shift the previously accumulated digits to the left.

    ```c
    d = (d * 10) + (s[i] - '0');
    ```

- **Overflow and Underflow Check**: The code also ensures that the result stays within the bounds of a 32-bit signed integer. If the result exceeds the maximum or minimum allowed value for a 32-bit integer, the function returns `INT_MAX` or `INT_MIN` accordingly.

    ```c
   if (d > (INT_MAX - (s[i] - '0')) / 10)
            if (c == 1) {
                return INT_MAX;
            }else {
                return INT_MIN;
            }
    ```

- **Returning the Final Result**: Finally, the function returns the result, multiplied by the sign (`+1` or `-1`), ensuring the correct final value is returned.

    ```c
    return (d * c);
    ```

## License

This project is licensed under the MIT License.
