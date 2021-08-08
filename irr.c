int shelf, pages;
            scanf("%d %d", &shelf, &pages);
            total_number_of_books[shelf]++;
            int *book = total_number_of_pages[shelf];
            while (*book != 0)
                book++;
            *book = pages;

int x, y;
            scanf("%d %d", &x, &y);
            total_number_of_books[x]++;
            int *book=total_number_of_pages[x];
            while(*book!=0)
            {
                book++;
            }
            *book=y;

            total_number_of_books = (int*)calloc(total_number_of_shelves, sizeof(int));

            total_number_of_books=(int*)malloc(total_number_of_shelves*sizeof(int));

            
            total_number_of_pages =(int**) malloc(total_number_of_shelves * sizeof(int *));
    for (int i = 0; i < total_number_of_shelves; i++) 
    {
        total_number_of_pages[i] = (int*)calloc(1100, sizeof(int));
    }

        total_number_of_pages =(int**)malloc(total_number_of_shelves*sizeof(int*));
    for(int i=0;i<total_number_of_shelves;i++)
    {
        total_number_of_pages[i]=(int*)malloc(1100*sizeof(int));
    }