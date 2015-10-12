import sys

_subsets = list()

def get_subsets(input_list, n, k, index, subset, i):
    global _subsets
    if index == k:
        _subsets.append(list(subset))
        return;
    
    if (i>=n):
        return
    else :
        #print "index ", index
        replace_or_insert(subset, index, input_list[i]) 
        #print subset
        get_subsets(input_list, n, k, index+1, subset, i+1)
        get_subsets(input_list, n, k, index, subset, i+1)

def replace_or_insert(inlist, index, item):
    length = len(inlist)
    if index <= length - 1:
        inlist[index] = item
    else:
        inlist.insert(index, item)

def main():
    input_list = [1, 2, 3, 4, 5]
    subset = []
    get_subsets(input_list, len(input_list), 2, 0, subset, 0)
    print _subsets

if __name__ == '__main__':
    main()