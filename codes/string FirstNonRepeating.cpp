string FirstNonRepeating(string s){
		    queue<char> q;
		    string ans="";
		    map<char,int> m;
		    
		    for(int i=0;i<s.size();i++)
		    {
		        m[s[i]]++;
		        q.push(s[i]);
		        
		        while(!q.empty() && m[q.front()]>1)
		        {
		            q.pop();
		        }
		        
		        if(q.empty())
		        ans+='#';
		        else ans+=q.front();
		        
		    }
		    return ans;
		}
