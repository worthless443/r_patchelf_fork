#include<stdint.h>
#include<stdio.h>
#include<assert.h>
int32_t convert(int32_t word) {
	int32_t r =  word;
	for(int n=1,i=1,flag=0xff;n<sizeof(int32_t);++n,i++,flag*=0x100) {
		if(i==3) i=1;
		if(!(r & flag)) r|=flag;
		if(i<=2)
			r |= (r & flag) << i*8;
		else 
			r |= (r & flag) >> i*8;
		printf("%x\n", r);
	

	}
	return r & 0xffff; // if word >> 16 is more than 0	
}

// FIXME, increase edian size 
long int long_convert(long int word) {
	long int r =  word;
	for(int n=1,i=1,flag=0xff;n<sizeof(long int);++n,i++,flag*=0x100) {
		if(i==4) i=1;
		if(!(r & flag)) r|=flag;
		if(n<=3) {
			r |= (r & flag) << i*8;
		}
		else  {
			r |= (r & flag) >> i*8;
		}
		//printf("%x\n", r);

	} 
	printf("cnd1 : %lx\n", r); // debug
	printf("cnd1 : %lx\n", r & 0xffffffff);
	return r & 0xffffffff; // if word >> 16 is more than 0	
}

unsigned int eadian_size(long int word) {
	unsigned int size = 0;
	for(int i=1;*(((unsigned char*)&word) + i);i++)  {// until zero byte
		if((*(((unsigned char*)&word) + i))==(unsigned char)word) size++;
	}

	return size;
}

int main() {
	long int r = long_convert(24);
	long int ri = convert(24);
	assert(eadian_size(r)>eadian_size(ri));
	if(r>ri) {
		printf("size long %d\n", eadian_size(r));
		printf("size %d\n", eadian_size(ri));
	}
}
