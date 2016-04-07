#include <stdio.h>
#include <stdlib.h>


/* define the given room types integers */

#define HALLWAY  1
#define BEDROOM  2
#define LIVING   3
#define BATHROOM 4
#define KITCHEN  5
#define LAUNDRY  6
#define STORAGE  7
#define GARAGE   8
#define BALCONY  9

void find_room_type(int room_type);

int main(int argc, char *argv[]) {
  int appartment_number,
    room_type,
    room_number;
  double xsize,
    ysize,
    total_area;

  /* take inputs in the appropriate format */
  while (scanf("%d", &appartment_number)==1) {

    total_area=0;

    /* print the title of the individual appartment's table */
    printf("Appartment %d\n", appartment_number);
    printf("--------------\n");

    /* generate the body of the table */
    while (scanf("%d", &room_type)==1){

      if (room_type==-1) {
        break;
      } 

      /* parse the room_type to a seperate function to avoid clutter */
      find_room_type(room_type);

      /* simply scan in the next few variables, and print them out */
      scanf("%d", &room_number);
      printf("%d  ", room_number);
      scanf("%lf", &xsize);
      scanf("%lf", &ysize);
      printf("%.2lf  %.2lf  %.2lf\n", xsize, ysize, xsize*ysize); //PLACEHOLDER MAYBE?? 

      total_area+=xsize*ysize;
    }
    printf("    Total area             %.2lf metres^2\n",total_area); 
  }
  return 0;
}




void
find_room_type(int room_type) {
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
