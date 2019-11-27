#include "PriorityQueue.h"

PriorityQueue* PQ_Create( int IntitialSize ) {
  PriorityQueue* NewPQ = (PriorityQueue*) malloc( sizeof( PriorityQueue ) );
  NewPQ->max_size = IntitialSize;
  NewPQ->size = 0;
  NewPQ->array = (Node*) malloc( sizeof ( Node ) * NewPQ->max_size );

  return NewPQ;
}

void PQ_Destroy( PriorityQueue* PQ ) {
  free( PQ->array );
  free( PQ );
}

void PQ_Enqueue( PriorityQueue* PQ, Node NewNode ) {
  int CurrentPosition = PQ->size;
  int ParentPosition  = PQ_GetParent( CurrentPosition );

  if ( PQ->size == PQ->max_size ) {
    if ( PQ->max_size == 0 )
      PQ->max_size = 1;

    PQ->max_size *= 2;
    PQ->array = (Node*) realloc( PQ->array, sizeof( Node ) * PQ->max_size );
  }

  PQ->array[CurrentPosition] = NewNode;

  while ( CurrentPosition > 0
      && PQ->array[CurrentPosition].Priority < PQ->array[ParentPosition].Priority ) {
    PQ_SwapNodes( PQ, CurrentPosition, ParentPosition );

    CurrentPosition = ParentPosition;
    ParentPosition  = PQ_GetParent( CurrentPosition );
  }

  PQ->size++;
}

void PQ_SwapNodes( PriorityQueue* PQ, int Index1, int Index2 ) {
  int CopySize = sizeof( Node );
  Node* Temp = (Node*)malloc(CopySize);

  memcpy( Temp,                &PQ->array[Index1], CopySize);
  memcpy( &PQ->array[Index1] , &PQ->array[Index2], CopySize);
  memcpy( &PQ->array[Index2] , Temp,               CopySize);

  free(Temp);
}

void PQ_Dequeue( PriorityQueue* PQ, Node* Root ) {
  int ParentPosition = 0;
  int LeftPosition   = 0;
  int RightPosition  = 0;

  memcpy(Root, &PQ->array[0], sizeof(Node));
  memset(&PQ->array[0], 0, sizeof(Node));

  PQ->size--;
  PQ_SwapNodes( PQ, 0, PQ->size );

  LeftPosition  = PQ_GetLeftChild( 0 );
  RightPosition = LeftPosition + 1;

  while ( 1 ) {
    int SelectedChild = 0;

    if ( LeftPosition >= PQ->size )
      break;

    if ( RightPosition >= PQ->size ) {
      SelectedChild = LeftPosition;
    }
    else {
      if ( PQ->array[LeftPosition].Priority > PQ->array[RightPosition].Priority)
        SelectedChild = RightPosition;
      else
        SelectedChild = LeftPosition;
    }

    if ( PQ->array[SelectedChild].Priority < PQ->array[ParentPosition].Priority) {
      PQ_SwapNodes(PQ, ParentPosition, SelectedChild);
      ParentPosition = SelectedChild;
    }
    else
      break;

    LeftPosition  = PQ_GetLeftChild(ParentPosition);
    RightPosition = LeftPosition + 1;
  }

  if ( PQ->size < ( PQ->max_size / 2 ) ) {
    PQ->max_size /= 2;
    PQ->array = (Node*) realloc( PQ->array, sizeof( Node ) * PQ->max_size );
  }
}

int PQ_GetParent( int Index ) {
  return (int) ((Index - 1) / 2);
}

int PQ_GetLeftChild( int Index ) {
  return (2 * Index) + 1;
}

int PQ_IsEmpty( PriorityQueue* PQ ) {
  return ( PQ->size == 0 );
}
