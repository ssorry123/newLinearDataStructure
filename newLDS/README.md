### ㅁ Contraints
##### - use int32_t  
##### - must be able to express from negative to positive, and zero  
- wrong order must be rejected and recorded
- auto-initialize to zero
<br>
<br>
<br>

### ㅁ nLDS (v.0.0)
```
```
<br>
---

### ㅁ Linked and Array(v.0.2)
```
# 
- one_thread (no lock)
- auto resize
- can make empty List (size 0)
- insertion can do only in index [0,size)
- append at end

# user function #
create_xxx_list(size)
destroy_xxx_list(list)
change_xxx_list(list)
at_xxx_list(list, idx)
insert_xxx_list(list, idx, item)
append_xxx_list(list, item)
remove_xxx_list(list, idx)
print_xxx_list_all(_Stream, list)

# ArrayList #
- list size != list capacity

# LinkedList #
- list size == list capacity
- doubly linked
```