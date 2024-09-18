string expand(string s) {
    if(s.length()==0){
        return "";
    }
    else if((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z')){
        return s[0]+expand(s.substr(1));
    }

    else if(s[0]>='2'&&s[0]<='9'){
        if(s[1]=='('){
            s[0]--;
            string x=expand('1'+s.substr(2));
            return x+expand(s[0]+s.substr(2))+expand(s.substr(1));

        }
        else{
            s[0]--;
            return expand('1'+s.substr(1))+expand(s);
        }
    }
    else if(s[0]=='1'){
        if(s[1]=='('){
            string x=expand(s.substr(2));
            return x+expand(s.substr(x.length()+3));
        }
        else{
            return expand(s.substr(1));
        }
    }
    else if(s[0]=='0'){
        return expand(s.substr(2+expand(s.substr(2)).length()));
    }
    else if(s[0]==')'){
        return "";
    }
    else if(s[0]=='('){
        int x=expand(','+s.substr(1)).length();

        return expand(s.substr(x+2));
    }
    else{
        if(s[1]=='('){
            string x=expand(','+s.substr(2));
            return "aa"+x+expand(','+s.substr(x.length()+3));
        }
        else if(s[1]==')'){
            return "";
        }
        else{
            return 'a'+expand(','+s.substr(2));
        }

    }
}