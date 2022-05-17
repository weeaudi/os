#include <stdint.h>
#include <stddef.h>
#include "KBScanCodeSet1.cpp"
#include <string>
#include <cstring>

extern "C" void InitilizeIDT();
extern "C" void print_char(char charecter);
extern "C" void print_str(char *charecter);
extern "C" void print_newline();
extern void outb(unsigned short port, unsigned char data);
extern unsigned char inb(unsigned short port);
extern void run_command(char* cmd);

char hexToStringOutput[128];
template <typename T>
char *HexToString(T value)
{
    T *valPtr = &value;
    uint8_t *ptr;
    uint8_t temp;
    uint8_t size = (sizeof(T)) * 2 - 1;
    uint8_t i;
    for (i = 0; i < size; i++)
    {
        ptr = ((uint8_t *)valPtr + i);
        temp = ((*ptr & 0xF0) >> 4);
        hexToStringOutput[size - (i * 2 + 1)] = temp + (temp > 9 ? 55 : 48);
        temp = ((*ptr & 0x0F));
        hexToStringOutput[size - (i * 2 + 0)] = temp + (temp > 9 ? 55 : 48);
    }
    hexToStringOutput[size + 1] = 0;
    return hexToStringOutput;
}

struct IDT64
{
    uint16_t offset_low;
    uint16_t selector;
    uint8_t ist;
    uint8_t types_attr;
    uint16_t offset_mid;
    uint32_t offset_high;
    uint32_t zero;
};
extern struct IDT64 _idt[256];
extern uint64_t isr1;
extern "C" void loadIDT();
extern void RemapPic();

void InitilizeIDT()
{
    _idt[1].zero = 0;
    _idt[1].offset_low = (uint16_t)(((uint64_t)&isr1 & 0x000000000000ffff));
    _idt[1].offset_mid = (uint16_t)(((uint64_t)&isr1 & 0x00000000ffff0000) >> 16);
    _idt[1].offset_high = (uint32_t)(((uint64_t)&isr1 & 0xffffffff00000000) >> 32);
    _idt[1].ist = 0;
    _idt[1].selector = 0x08;
    _idt[1].types_attr = 0x8e;

    RemapPic();

    outb(0x21, 0xfd);
    outb(0xa1, 0xff);
    loadIDT();
}

char *tmp;

char *append(char* inputlist, char charec) {
    for (size_t i = 0; 1; i++) {
        char chara = inputlist[i];
		tmp[i] = chara;
        if (chara == '\0') {
            tmp[i] = charec;
			tmp[i+1] = '\0';
			return tmp;
        }
    }
}

uint8_t shift = 0x00;
char *inputcmd = (char*) "";

extern "C" void isr1_handler()
{
    uint8_t scancode = inb(0x60);
    int len = *(&KBSet1::ScanCodeLookupTable + 1) - KBSet1::ScanCodeLookupTable;
    if (scancode == 0x1C){
        run_command(inputcmd);
        inputcmd = (char*) "";
        outb(0x20, 0x20);
        outb(0xa0, 0x20);
        return;
    }
    if (scancode == 0x2A || scancode == 0x36)
    {
        shift = 0xAA;
    }
    if (scancode == 0xAA || scancode == 0xB6)
    {
        shift = 0x00;
    }
    if ((shift == 0x00) & (scancode != 0x2A) & (scancode != 0x36))
    {
        if (scancode < len)
        {
			inputcmd = append(inputcmd, KBSet1::ScanCodeLookupTable[scancode]);
            print_char(KBSet1::ScanCodeLookupTable[scancode]);
			
        }
    }
    if ((shift == 0xAA) & (scancode != 0x2A) & (scancode != 0x36)){
        if (scancode < len)
        {
			inputcmd = append(inputcmd, KBSet1::ShiftScanCodeLookupTable[scancode]);
            print_char(KBSet1::ShiftScanCodeLookupTable[scancode]);
			
        }
    }
    //print_str(HexToString(scancode));
    outb(0x20, 0x20);
    outb(0xa0, 0x20);
}