//------------------------------------------------
//               Ch16_04_misc.cpp
//------------------------------------------------

#include <stdexcept>
#include <random>
#include "Ch16_04.h"
#include "MatrixF32.h"
#include "AlignedMem.h"

bool CheckArgs(const Vec4x1_F32* vec_b, const MatrixF32& m, const Vec4x1_F32* vec_a, size_t num_vec)
{
    if (num_vec == 0)
        return false;

    if (m.GetNumRows() != 4 || m.GetNumCols() != 4)
        return false;

    if (!AlignedMem::IsAligned(m.Data(), c_Alignment))
        return false;

    if (!AlignedMem::IsAligned(vec_a, c_Alignment))
        return false;

    if (!AlignedMem::IsAligned(vec_b, c_Alignment))
        return false;

    return true;
}

void Init(MatrixF32& m, Vec4x1_F32* va, size_t num_vec)
{
    if (m.GetNumRows() != 4 || m.GetNumCols() != 4)
        throw std::runtime_error("Init() - invalid matrix size");
    
    const float a_row0[] = { 10.0, 11.0, 12.0, 13.0 };
    const float a_row1[] = { 20.0, 21.0, 22.0, 23.0 };
    const float a_row2[] = { 30.0, 31.0, 32.0, 33.0 };
    const float a_row3[] = { 40.0, 41.0, 42.0, 43.0 };
    m.SetRow(0, a_row0);
    m.SetRow(1, a_row1);
    m.SetRow(2, a_row2);
    m.SetRow(3, a_row3);

    std::mt19937 rng {c_RngSeedVal};
    std::uniform_int_distribution<int> dist {c_RngMinVal, c_RngMaxVal};

    for (size_t i = 0; i < num_vec; i++)
    {
        va[i].W = (float)dist(rng);
        va[i].X = (float)dist(rng);
        va[i].Y = (float)dist(rng);
        va[i].Z = (float)dist(rng);
    }

    if (num_vec >= 4)
    {
        // Use known values for test & debug
        va[0].W =  5; va[0].X =  6; va[0].Y =  7; va[0].Z =  8;
        va[1].W = 15; va[1].X = 16; va[1].Y = 17; va[1].Z = 18;
        va[2].W = 25; va[2].X = 26; va[2].Y = 27; va[2].Z = 28;
        va[3].W = 35; va[3].X = 36; va[3].Y = 37; va[3].Z = 38;
    }
}

bool VecCompare(const Vec4x1_F32* v1, const Vec4x1_F32* v2)
{
    static const float epsilon = 1.0e-12f;

    bool b0 = (fabs(v1->W - v2->W) <= epsilon);
    bool b1 = (fabs(v1->X - v2->X) <= epsilon);
    bool b2 = (fabs(v1->Y - v2->Y) <= epsilon);
    bool b3 = (fabs(v1->Z - v2->Z) <= epsilon);

    return b0 && b1 && b2 && b3;
}
