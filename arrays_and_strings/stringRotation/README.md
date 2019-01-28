# 1.9 String Rotation

Assume you have a method `isSub5tring` whichchecks if one word is a substring of another. Given two strings, `s1` and `s2`, write code to check if `s2` is a rotation of s1 using only one call to `isSubstring` (e.g., "waterbottle" is a rotation of "erbottlewat").

My solution - We can concatenate the string to itself and use an index counter to loop through the string for `s.length()` many times. If a perfect match is found then the two words are rotations of each otherwise they are not. 
