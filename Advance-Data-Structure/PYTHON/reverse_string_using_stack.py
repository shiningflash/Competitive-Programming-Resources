def reverse_str(name):
    import stack
    st = stack.Stack()
    
    rev_name = ''
    
    for c in name:
        st.push(c)
    
    while not st.is_empty():
        rev_name += st.pop()
    
    return rev_name

if __name__ == '__main__':
    name = 'AIRAF NUZIAF'
    print(reverse_str(name))