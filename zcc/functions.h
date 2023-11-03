#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

// Fast random package
#define myRand() ((unsigned char)((unsigned int)(rand())%256))

void SetButtons(unsigned char inverse);
void InitConsole();
void InitStage(unsigned char resetsound);
void ClearScreen();
void ClearBackground(unsigned int b);
void LoadGraphics(unsigned char *pal, unsigned char palbank,char *psg,unsigned char psgbank,char *bin, unsigned char binbank, unsigned int size);
void LoadSprite(const unsigned char *psg,unsigned int base,unsigned char bank);
void UpdateStage();
void StopSound();
unsigned char putCharacter(unsigned char a,unsigned char x, unsigned char y);
void WriteText(const unsigned char *text,unsigned char x, unsigned char y);
void PlayMusic(const unsigned char *music,unsigned char mbank,unsigned char looped);
void DoFadeIn(const unsigned char *palettefadepalette,unsigned char palettefadebank);
void changeBank(unsigned char b);
void WriteNumber(unsigned int i,unsigned char d,unsigned char x, unsigned char y);
void PlaySound(char *sound,unsigned char sbank, unsigned char priority,unsigned char channel);
void checkgamepause();
void DrawSpriteArray(unsigned char s,unsigned char px,unsigned char py,unsigned char tx, unsigned char ty,unsigned char t);
void DoPaletteFade(unsigned char a,const unsigned char *c, unsigned char b);
void DoFadeOut();
void PutChars(unsigned char x, unsigned char y,unsigned char w, unsigned char h,unsigned int l);
void ClearSprites();

#endif
