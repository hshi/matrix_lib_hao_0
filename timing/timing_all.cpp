#include "matrix_all.h"

using namespace std;
using namespace matrix_hao_lib;

#ifdef USE_MAGMA
namespace matrix_hao_lib
{
    void bl_cpu_magma_timing();
}
#endif

int main(int argc, char** argv)
{
    int rank=0;

#ifdef MPI_HAO
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif

    if(rank==0)
    {
        cout<<"\n\nThis timing program compares the time cost between CPU lapack and MAGMA lapack."<<endl;
        cout<<"It requires large memory and long computational time if USE_MAGMA=on, else does nothing."<<endl;
        cout<<"Please submit the job if you are using a cluster, it takes ~10 minutes."<<endl;
        cout<<"\n=======Start timing======="<<endl;
        
    }

#ifdef USE_MAGMA
    magma_init();


    if(rank==0)
    {
        bl_cpu_magma_timing();
    }



    magma_finalize();
#endif



#ifdef MPI_HAO
    MPI_Finalize();
#endif

    return 0;
}
