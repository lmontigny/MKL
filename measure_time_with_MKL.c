/* C source code is found in matrix_multiplication.c */

    printf (" Making the first run of matrix product using triple nested loop\n"
            " to get stable run time measurements \n\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            sum = 0.0;
            for (l = 0; l < k; l++)
                sum += A[k*i+l] * B[n*l+j];
            C[n*i+j] = sum;
        }
    }

    printf (" Measuring performance of matrix product using triple nested loop \n\n");
    s_initial = dsecnd();
    for (r = 0; r < LOOP_COUNT; r++) {
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                sum = 0.0;
                for (l = 0; l < k; l++)
                    sum += A[k*i+l] * B[n*l+j];
                C[n*i+j] = sum;
            }
        }
    }
    s_elapsed = (dsecnd() - s_initial) / LOOP_COUNT;
    
    printf (" == Matrix multiplication using triple nested loop completed == \n"
            " == at %.5f milliseconds == \n\n", (s_elapsed * 1000));
