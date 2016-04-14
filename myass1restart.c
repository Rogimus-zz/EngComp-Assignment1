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

typedef struct {
  double dry_area;
  double dry_area_percent;
  double wet_area;
  double wet_area_percent;
  double storage_area;
  double storage_area_percent;
} areas_t;

void Print_Room_Type(int room_type);

areas_t Print_Room_Area(appartment_t x);

int main(int argc, char *argv[]) {
  double area_sum; 
  int room_index,
    appartment_index,
    num_appartments,
    i;

  areas_t appartment_area;

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
  for (i = 0; i < num_appartments ; i++) {
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

  /*stage 4 */
  for ( i = 0; i < num_appartments; i++) {
    appartment_area = Print_Room_Area(appartments[i]);
    printf("|  %3d  | %5.2lf %5.1lf%% | %5.2lf %5.1lf%% | %5.2lf %5.1lf%% |\n",
           appartments[i].appartment_number,
           appartment_area.dry_area,
           appartment_area.dry_area_percent,
           appartment_area.wet_area,
           appartment_area.wet_area_percent,
           appartment_area.storage_area,
           appartment_area.storage_area_percent);
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
  } else if (room_type == BALCONY) {
    printf("    Balcony  ");
  } else {
    exit(EXIT_FAILURE);
  }
}

areas_t
Print_Room_Area(appartment_t x){
  areas_t areas;
  int i;

  areas.dry_area = areas.dry_area_percent = areas.wet_area =
    areas.wet_area_percent = areas.storage_area = areas.storage_area_percent
    = 0;

  i=0;
  while( x.room[i].room_type != -1 ) {
    if( x.room[i].room_type == HALLWAY || x.room[i].room_type == BEDROOM ||
        x.room[i].room_type == LIVING ) {
      areas.dry_area+= x.room[i].area;
    } else if( x.room[i].room_type == BATHROOM || x.room[i].room_type == KITCHEN ||
               x.room[i].room_type == LAUNDRY) {
      areas.wet_area+= x.room[i].area;
    } else if( x.room[i].room_type == STORAGE || x.room[i].room_type == GARAGE ||
        x.room[i].room_type == BALCONY) {
      areas.storage_area+= x.room[i].area;
    } else {
      exit(EXIT_FAILURE);
    }
    i++;

  }

  areas.dry_area_percent = 100 * areas.dry_area/ x.total_area;
  areas.wet_area_percent = 100 * areas.wet_area/ x.total_area;
  areas.storage_area_percent = 100 * areas.storage_area/ x.total_area;
 
  return areas;
}
