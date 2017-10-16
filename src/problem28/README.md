#Solution#

* 注意当匹配过程中发现中间值不相等，需要退回在重新匹配，否则会发生漏判现象

* solution1中就不会存在上述问题，因为在每个haystack的index上再加上for循环进行匹配，匹配过程中，haystack的for循环的index保持不变