class DSP : public Processor {
public:
  uint8 read(uint8 addr);
  void synchronize();
  void write(uint8 addr,uint8 data);
  void power(); void reset();
  DSP();
  topgear_dsp core;
};
extern DSP dsp;
