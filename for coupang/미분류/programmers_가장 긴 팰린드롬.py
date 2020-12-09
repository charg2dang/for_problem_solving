def is_palindrome( str ) -> bool :
    str_len = len(str);

    half_str_len = str_len // 2;

    for i in range(half_str_len):
        if str[i] != str[-(i+1)] :
            return False;

    return True;


def solution( s ) -> int :
    answer = 0;

    s_len = len(s);

    for i in range(s_len):
        len_offset = s_len - i;
        
        for j in range(0, i + 1):
            if True == is_palindrome(s[j: j + len_offset]) :
                return len_offset;


print(solution("abcdcba"))
print(solution("abacde"))