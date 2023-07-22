    // for n value 
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        st.push(x);
    }

    while (!st.empty())
    {
        cout<<st.top() <<endl;
        st.pop();
    }