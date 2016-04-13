/* coding is fun */
#include <stdio.h>
#include <stdlib.h>


/* define the given room_types integers */

#define HALLWAY  1
#define BEDROOM  2
#define LIVING   3
#define BATHROOM 4
#define KITCHEN  5
#define LAUNDRY  6
#define STORAGE  7
#define GARAGE   8
#define BALCONY  9


#define MAXROOMS 100
#define MAXAPPARTMENTS 100

typedef struct {
  int room_type;
  int room_occurence;
  double xsize;
  double ysize;
  double area;
} room_t;

typedef struct {
  int appartment_number;
  room_t room[MAXROOMS];
  double total_area;
} appartment_t;


void Print_Room_Type(int room_type);



int main(int argc, char *argv[]) {
  double area_sum; 
  int room_index,
    appartment_index,
    num_appartments,
    i;

  appartment_t appartments[MAXAPPARTMENTS];

  appartment_index = 0;

  num_appartments = 0;
  /* scan in the relevant data */
  while ( scanf("%d", &appartments[appartment_index].appartment_number) == 1 ) {

    room_index = 0;
    while( scanf("%d", &appartments[appartment_index].room[room_index].room_type) == 1 ) {
      if( appartments[appartment_index].room[room_index].room_type == -1 ) {
        appartment_index++;
        num_appartments++;
        break;
      } else {

        scanf("%d %lf %lf",
              &appartments[appartment_index].room[room_index].room_occurence,
              &appartments[appartment_index].room[room_index].xsize,
              &appartments[appartment_index].room[room_index].ysize);

        appartments[appartment_index].room[room_index].area =
          appartments[appartment_index].room[room_index].xsize
          * appartments[appartment_index].room[room_index].ysize;
        appartments[appartment_index].total_area += appartments[appartment_index].room[room_index].area;
      }
      room_index++;
    }
  }


  /* PRINT THE RESULTS */

  /* print the title of the individual appartment's table */
  for (i = 0; i < num_appartments ; i++){
    printf("Appartment %d\n", appartments[i].appartment_number);
    printf("--------------\n");


    room_index = 0;
    area_sum = appartments[i].room[room_index].area;
    while( appartments[i].room[room_index].room_type != -1 ){
      Print_Room_Type(appartments[i].room[room_index].room_type);
      
      if ( appartments[i].room[room_index].room_type ==
           appartments[i].room[room_index+1].room_type &&
           appartments[i].room[room_index].room_occurence ==
           appartments[i].room[room_index+1].room_occurence) {
        
        printf("%d %5.2lf %5.2lf   ---\n",
               appartments[i].room[room_index].room_occurence,
               appartments[i].room[room_index].xsize,
               appartments[i].room[room_index].ysize);
        
        area_sum += appartments[i].room[room_index+1].area;
      } else {
        printf("%d %5.2lf %5.2lf %6.2lf\n",
               appartments[i].room[room_index].room_occurence,
               appartments[i].room[room_index].xsize,
               appartments[i].room[room_index].ysize,
               area_sum);
        area_sum = appartments[i].room[room_index+1].area;
      }
      room_index++;
    }
    printf("    Total area              %.2lf metres^2\n\n",appartments[i].total_area);
  }
  return 0;
}

void
Print_Room_Type(int room_type ) {

  if (room_type == HALLWAY) {
    printf("    Hallway  ");

  } else if (room_type == BEDROOM) {
    printf("    Bedroom  ");
  } else if (room_type == LIVING) {
    printf("    Living   ");
  } else if (room_type == BATHROOM) {
    printf("    Bathroom ");
  } else if (room_type == KITCHEN) {
    printf("    Kitchen  ");
  } else if (room_type == LAUNDRY) {
    printf("    Laundry  ");
  } else if (room_type == STORAGE) {
    printf("    Storage  ");
  } else if (room_type == GARAGE) {
    printf("    Garage   ");
  } else {
    printf("    Balcony  ");
  }
}
