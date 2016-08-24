from larlite import larlite as ll
import sys,os

sm1 = ll.storage_manager()
sm2 = ll.storage_manager()
sm3 = ll.storage_manager()

sm1.set_io_mode(ll.storage_manager.kREAD)
sm2.set_io_mode(ll.storage_manager.kREAD)
sm3.set_io_mode(ll.storage_manager.kWRITE)

FF='/Users/vgenty/sw/larlite/UserDev/sntest/FrameRollover/mac'

sm1.add_in_filename(os.path.join(FF,"aho_snova.root"))
sm2.add_in_filename(os.path.join(FF,"aho_trig.root"))
sm3.set_out_filename("aho_align.root");

sm1.enable_event_alignment(False)
sm2.enable_event_alignment(False)

sm1.open()
sm2.open()
sm3.open()

sm1.next_event()
sm2.next_event()
sm3.next_event()

align=ll.Align()

print align.align_events(sm1,sm2,sm3)

sm1.close()
sm2.close()
sm3.close()

sys.exit(1)

