class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>file = {folder[0]};
        for(int fld = 1; fld<folder.size();fld++){
            if(folder[fld].substr(0,file.back().size() + 1)!= file.back()+ '/')
             file.push_back(folder[fld]);
        }
        return file;
    }
};