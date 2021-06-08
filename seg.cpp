int n;
int s1[4*100000+1],s2[4*100000+1];

void build(sum,array size,int a[],int sum[],int i){
    //query(sum,n-1,left,right,array,1); 
    if(s>e){
        return;
    }
    if(s==e){
        sum[i]=a[s];
        return;
    }
/*array of 2n elements 

parent of a[i] is a[i/2]

left of a[i] is at a[2i]
 
right of a[i] is at a[2i+1]

we have all the left childs are at even indexes and right at odd 

in the q we have to make 2 seg
*/

    int mid=(s+e)/2;

    build(s,mid,a,sum,2*i);
    build(mid+1,e,a,sum,2*i+1);

    sum[i]=sum[2*i]+sum[2*i+1];

    return;
}
//build(0,n-1,v,array,1);
int query(int s,int e,int l,int r,int sum[],int i){

    if(l<=s && r>=e){
        return sum[i];
    }
    if(s>r || e<l){
        return 0;
    }

    int mid=(s+e)/2;

    return query(s,mid,l,r,sum,2*i)+query(mid+1,e,l,r,sum,2*i+1);
}

int32_t main(){
    
    build(0,n-1,v,s1,1);
 
    int m;
    cin>>m;
    int t,l,r;
    fo(i,1,m){
        cin>>t>>l>>r;
        // watch(t);watch(l);watch(r);
        if(t==1){
            cout<<query(sum,n-1,left,right,first array,1)<<"\n"; 
        }
        
}
//https://codeforces.com/blog/entry/18051

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  modify(0, 1);
  printf("%d\n", query(3, 11));
  return 0;
}
//