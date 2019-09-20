import lldb
import time
import commands
import shlex

def	color_reset_funct(debugger, command, result, internal_dict):
	print("\033[0m")

def	color_bold_funct(debugger, command, result, internal_dict):
	print("\033[1m")

def	color_underline_funct(debugger, command, result, internal_dict):
	print("\033[4m")

def	color_blink_funct(debugger, command, result, internal_dict):
	print("\033[5m")

def	color_black_funct(debugger, command, result, internal_dict):
	print("\033[30m")

def	color_red_funct(debugger, command, result, internal_dict):
	print("\033[31m")

def	color_green_funct(debugger, command, result, internal_dict):
	print("\033[32m")

def	color_yellow_funct(debugger, command, result, internal_dict):
	print("\033[33m")

def	color_blue_funct(debugger, command, result, internal_dict):
	print("\033[34m")

def	color_magenta_funct(debugger, command, result, internal_dict):
	print("\033[35m")

def	color_cyan_funct(debugger, command, result, internal_dict):
	print("\033[36m")

def	color_white_funct(debugger, command, result, internal_dict):
	print("\033[37m")

def reverse_funct(debugger, command, result, internal_dict):
	target = debugger.GetSelectedTarget()
	if not target:
		print("Error: there is no target")
	else:
		print("FT_"+str(target)[::-1])

def get_arch_funct(debugger, command, result, internal_dict):
	target = debugger.GetSelectedTarget()
	if not target:
		print("Error: there is no target")
	else:
		print(target.triple.split('-')[0])

def run_all_funct(debugger, command, result, internal_dict):
	args = shlex.split(command)
	if len(args) is not 3:
		print("Error: invalid arguments number: 3 required")
		return
	debugger.SetAsync(True)
	debugger.HandleCommand('breakpoint set -o -l 18')
	debugger.HandleCommand('breakpoint set -p "std::cin|tmp /= max|return biggest"')
	time.sleep(0.5)
	debugger.HandleCommand('process launch')
	time.sleep(0.5)
	debugger.HandleCommand('expression -- $rsi -= 4')
	time.sleep(0.5)
	debugger.HandleCommand('process continue')
	time.sleep(0.5)
	debugger.GetSelectedTarget().GetProcess().PutSTDIN(args[0]+"\n")
	time.sleep(0.5)
	debugger.HandleCommand('process continue')
	time.sleep(0.5)
	debugger.GetSelectedTarget().GetProcess().PutSTDIN(args[1]+"\n")
	time.sleep(0.5)
	debugger.HandleCommand('expression -- $rsi += 4')
	time.sleep(0.5)
	debugger.HandleCommand('process continue')
	time.sleep(0.5)
	debugger.GetSelectedTarget().GetProcess().PutSTDIN(args[2]+"\n")
	time.sleep(0.5)
	debugger.HandleCommand('expression -- count = 0')
	time.sleep(0.5)
	debugger.HandleCommand('process continue')
	time.sleep(0.5)
	debugger.HandleCommand('expression -- tmp = min[0] + min[1] + min[2]')
	time.sleep(0.5)
	debugger.HandleCommand('process continue')
	time.sleep(0.5)
	debugger.HandleCommand('expression -- biggest = (min[0] >= min[1] ? (min[0] >= min[2] ? min[0] : min[2]) : (min[1] >= min[2] ? min[1] : min[2]))')
	time.sleep(0.5)
	debugger.HandleCommand('process continue')

def ls_funct(debugger, command, result, internal_dict):
	print >>result, (commands.getoutput('ls %s' % command))

def pwd_funct(debugger, command, result, internal_dict):
	print >>result, (commands.getoutput('pwd %s' % command))

def liste_funct(debugger, command, result, internal_dict):
	print("reverse")
	print("run_all")
	print("print_frame")
	print("get_arch")
	print("ftc")
	print("ls")
	print("pwd")
	print("color_reset")
	print("color_underline")
	print("color_bold")
	print("color_red")
	print("color_black")
	print("color_green")
	print("color_yellow")
	print("color_blue")
	print("color_magenta")
	print("color_cyan")
	print("color_white")
	print("color_blink")

def print_frame_funct(debugger, command, result, internal_dict):
	target = debugger.GetSelectedTarget()
	process = target.GetProcess()
	thread = process.GetSelectedThread()

	for frame in thread:
		print >>result, str(frame)

def ftc_funct(debugger, command, result, internal_dict):
	n = shlex.split(command)
	if len(n) is not 1:
		print("Error: 1 argument is required")
		return
	try:
		n = int(n[0])
	except:
		print("Error: an integer is required")
		return
	
	debugger.SetAsync(True)
	for i in range(0, n):
		debugger.HandleCommand('process continue')
	debugger.SetAsync(False)

def __lldb_init_module(debugger, internal_dict):
	debugger.HandleCommand('command script add -f reverse.liste_funct liste')
	debugger.HandleCommand('command script add -f reverse.print_frame_funct print_frame')
	debugger.HandleCommand('command script add -f reverse.reverse_funct reverse')
	debugger.HandleCommand('command script add -f reverse.run_all_funct run_all')
	debugger.HandleCommand('command script add -f reverse.get_arch_funct get_arch')
	debugger.HandleCommand('command script add -f reverse.ls_funct ls')
	debugger.HandleCommand('command script add -f reverse.pwd_funct pwd')
	debugger.HandleCommand('command script add -f reverse.ftc_funct ftc')
	debugger.HandleCommand('command script add -f reverse.color_reset_funct color_reset')
	debugger.HandleCommand('command script add -f reverse.color_underline_funct color_underline')
	debugger.HandleCommand('command script add -f reverse.color_bold_funct color_bold')
	debugger.HandleCommand('command script add -f reverse.color_red_funct color_red')
	debugger.HandleCommand('command script add -f reverse.color_black_funct color_black')
	debugger.HandleCommand('command script add -f reverse.color_green_funct color_green')
	debugger.HandleCommand('command script add -f reverse.color_yellow_funct color_yellow')
	debugger.HandleCommand('command script add -f reverse.color_blue_funct color_blue')
	debugger.HandleCommand('command script add -f reverse.color_magenta_funct color_magenta')
	debugger.HandleCommand('command script add -f reverse.color_cyan_funct color_cyan')
	debugger.HandleCommand('command script add -f reverse.color_white_funct color_white')
	debugger.HandleCommand('command script add -f reverse.color_blink_funct color_blink')
