./push_swap -

-takes input via a single argument
-validates input and sends an int array to get sorted
-writes list of rules/operations to stdout which is piped to ./checker

./checker -

-takes input via a single argument && reads each rules/operator one at a time
	from stdin using get_next_line()
-validates input in the same way as ./push_swap
-compares our list to ideal sorted list and displays OK/KO

TO COMPILE--
type:
sh comp_all.sh
