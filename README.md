## newLinearDataStructure
###### nLDS
###### first self-directed project
###### *for now, using C,,, using python or cc later if possible*
###### 코드의 주석은 주로 한국어 (comment in codes -> Korean)
<br>

---

### ㅁ What
#### **nLDS = Linked (List) + Array (List)**
##### with the good points stated below,
##### without the so-so points stated below,
###### *of course, nLDS should be no great waste of space*    

    
#### ordinary,,
1. Linked list
    - good  
    fast insert(at beginning, end)  
    fast insert(at mid) (searchtime+O(1))  
    fast resize (no copy)
    - so-so  
    slow search(indexing)  
    slow change(searchtime + O(1))
1. Array  
    - good  
    fast search(indexing)  
    fast change item (indexing)  
    fast insert(at end)  
    - so-so  
    slow insert(at beginning, middle)
    slow resize(O(n) copy)

<br>

---

### ㅁ Contraints
##### - use int32_t  
##### - must be able to express from negative to positive, and zero  
- wrong order must be rejected and recorded
- auto-initialize to zero

<br>

---

### ㅁ Info of file (mean,, current status)

### Common Linked and Array
- no, zero size List
- for using, have to declare List Size  
- can change size by user
- insertion and deletion can cause auto size changes (+-1)
- one-thread (no lock)
- append(like python list method) implemented in insert
#### Linked (v.0.1)  
- singlely linked list
- size == capacity
#### Array (v.0.1)
- size != capacity

<br>

### nLDS (v.0.0)
- 

<br>

---

### ㅁ Process
1. make normal Linked List & Array List
1. make nLDS
1. test
1. compare
1. improve nLDS
1. and Repetition...  

<br>

---

### ㅁ How  
#### preparing  


<br>

---

### ㅁ Test
#### preparing  

<br>

---

### ㅁ Environment
#### my Laptop  
#### Windows 10  
#### 8GB RAM  
#### Intel Core i7-4550U CPU  
#### Visual Studio 2019, x64  
#### *Visual Studio Code*
---