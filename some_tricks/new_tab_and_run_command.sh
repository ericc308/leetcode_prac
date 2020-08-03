gnome-terminal --tab -x ./radar_center -j ~/job -t ~/tronfuturetech/tx_pulse_def.json -l debug
gnome-terminal --tab -x ./radar_agent -j ~/job -d ~/tronfuturetech -p ~/tronfuture/release/v0.10.2/default_dsp_config.json --clean=0 --save=1 -l debug
# gnome-terminal --tab -x python3 ~/git_lab/Radar-Executor-Fake/codes/python/fake_executor/fake_executor.py -s ~/reference -j ~/job
gnome-terminal --tab -x python3 ~/git_lab/tools/fake_gui/fake_gui.py -i localhost -p 1883