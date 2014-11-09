

#define PREFIX AGM
#define COMPONENT CrewInfo


#define DOUBLES(A,B) ##A##_##B
#define TRIPLES(A,B,C) ##A##_##B##_##C
#define QUOTE(A) #A
#define CONCAT(A,B) A####B

#define GVAR(A) TRIPLES(PREFIX,COMPONENT,A)
#define QGVAR(A) QUOTE(GVAR(A))





#define OPTION(A) COMPONENT##_A
#define QOPTION(A) QUOTE(OPTION(A))

#define GET_OPTION_VALUE (A,DEFAULT) profileNamespace getVariable [QOPTION(A) , DEFAULT]