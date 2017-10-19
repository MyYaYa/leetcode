#Solution#

*	For char c = '1', to_string(count) is slower that (char s = '1' + count - 1;), which use ascii code property.
*	Recursively call function is obviously slower than loop. So, if we can use loop, not to try recursion.