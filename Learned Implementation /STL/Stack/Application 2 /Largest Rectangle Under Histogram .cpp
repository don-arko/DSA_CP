
//Idea : Iterate on height , and let the curr height be max height of the reactangle hence this shall be the min heigh among all the  consecutive bars
//       then lets find the maximum width for this height which can be found using next smaller element and prev smaller element width = (pse,nse) 
//       this is the max width and also the max height possible for this curr height and hence both the factors in area are maximised to the very best
//       
int largest_area(vector<int> h,vector<int> nse,vector<int> pse){
    int ar=0;
    for(int i=0;i<h.size();++i){ 
        int w=nse[i]-pse[i]-1;
        ar=max(ar,h[i]*w);
    }
}
