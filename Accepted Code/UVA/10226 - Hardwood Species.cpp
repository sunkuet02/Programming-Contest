map<string, int> trees;

int main() {
    //Read;
    int test;
    
    cin >> test;
    
    getchar();
    getchar();
    
    for(int t = 1; t <= test; t++) {
        
        trees.clear();
        if(t != 1) cout << endl;
        
        string name;
        int total_tree = 0;
        
        while(getline(cin, name)) {
            if(name.size() == 0 || name == "") break;

            total_tree ++;
            trees[name] ++ ;
        }
        
        map<string, int>::iterator it;
        
        for(it = trees.begin(); it != trees.end(); it ++) {
            cout << it->first << " ";
            printf("%.4lf\n", it->second * 100.0 / total_tree);
        }
    }
}
