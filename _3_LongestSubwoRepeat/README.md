# Longest Substring without Repeat
  1. create func isRepeated(string in, char compare)
  2. add next char after comparing to current maximum non repeated string.
  3. if repeated happens, current max become string cut from the next one of repeated char to the end of old max string and add the repeated char.
