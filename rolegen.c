#include<stdio.h>
struct student{
	char name[30];
	int roll,age;
};
struct student ip(struct student s)
{
	char tmp[4];
	printf("\nEnter the name\n");
	fgets(s.name,sizeof(s.name),stdin);
	printf("\nEnter the age\n");
	fgets(tmp,sizeof(tmp),stdin);
	sscanf(tmp,"%d",&s.age);
	return s;
}
void generateroll(struct student *s)
{
	static int r=1;
	/*(*s).roll=r;*/
	/*defreferncing a structure*/
	s->roll=r;
	r++;
}
void op(struct student s)
{
	printf("\nname=%s",s.name);
	printf("\nage=%d",s.age);
	printf("\nroll=%d",s.roll);
}
int main()
{
	struct student s1,s2,s3;
	//s1=ip();
    ip(s1);
	generateroll(&s1);
	//s2=ip();
    ip(s2);
	generateroll(&s2);
	//s3=ip();
    ip(s3);
	generateroll(&s3);
	op(s1);
	op(s2);
	op(s3);
	return 0;
}
	
	