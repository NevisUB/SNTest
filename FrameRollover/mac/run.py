import sys

if len(sys.argv) < 2:
    msg  = '\n'
    msg += "Usage 1: %s $INPUT_ROOT_FILE(s)\n" % sys.argv[0]
    msg += '\n'
    sys.stderr.write(msg)
    sys.exit(1)

from larlite import larlite as fmwk

my_proc = fmwk.ana_processor()

for x in xrange(len(sys.argv)-3):
    my_proc.add_input_file(sys.argv[x+3])

my_proc.set_io_mode(fmwk.storage_manager.kBOTH)

kind=sys.argv[1]

my_proc.set_output_file("aho_%s.root"%kind)

rolo=fmwk.Rolodex()
rolo.SetProducer("%s"%kind)

stitch=fmwk.StitchAlgo()
stitch.SetPreSamples(8)
    
rolo.SetStitcher(stitch)

my_proc.add_process(rolo)

# Let's run it.
my_proc.run(0,10*int(sys.argv[2]));

sys.exit(0)
