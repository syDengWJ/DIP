
Thresholding1ps.dll: dlldata.obj Thresholding1_p.obj Thresholding1_i.obj
	link /dll /out:Thresholding1ps.dll /def:Thresholding1ps.def /entry:DllMain dlldata.obj Thresholding1_p.obj Thresholding1_i.obj \
		kernel32.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
.c.obj:
	cl /c /Ox /DREGISTER_PROXY_DLL \
		$<

clean:
	@del Thresholding1ps.dll
	@del Thresholding1ps.lib
	@del Thresholding1ps.exp
	@del dlldata.obj
	@del Thresholding1_p.obj
	@del Thresholding1_i.obj
