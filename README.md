python3.10-jammy
================

a small patch fixing `virtualenv` / `build` for python3.10 on ubuntu jammy

ppa: https://launchpad.net/~deadsnakes/+archive/ubuntu/python3.10-jammy

## installation

```bash
add-apt-repository ppa:deadsnakes/python3.10-jammy
```

## about

these packages may also work on debian unstable, though no guarantees.

this package provides a drop-in `python3.10-*` package with this small patch on
top of upstream:

```diff
diff --git a/Lib/sysconfig.py b/Lib/sysconfig.py
index a218726..f44f97c 100644
--- a/Lib/sysconfig.py
+++ b/Lib/sysconfig.py
@@ -81,6 +81,7 @@ _INSTALL_SCHEMES = {
         'data': '{base}',
         },
     }
+_INSTALL_SCHEMES['venv'] = _INSTALL_SCHEMES['posix_prefix']

 # NOTE: site.py has copy of this function.
```
