We call swap rather than exchange the values of *beg and *end directly, reasons as follows:
```
template <class In>
void reverse(In begin,In end)
{
    while(begin!=end)
    {
        --end;
        if(begin!=end)
        {
            swap(*begin++,*end);
        }
    }
}
```
swap(*begin++,*end);
if we use:
```
temp=*begin++;//then begin's value is changed(direct to it next element)
*begin=*end;
*end=temp;
```
or
```
temp=*end;
*end=*begin++;//also the same,
*begin=temp;
```
but we can do like this, and it will work:
```
if(begin!=end)
{
	In::value_type temp;
	temp=*begin;
	*begin=*end;
	*end=temp;
	++begin;
}
```

