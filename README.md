This is LANL code C17146

-------------------------

# Setup stuff

You need to create the following directories in the same directory as the makefile

```
obj/
exec/
input/
Data/
```


To build the code, simply type

make

to build the 'main' multiBGK code, which can do 1D-3V or 0D-3V, for an arbitrary number of species.

------------
# Note for developers
-----------

When you install this package, please also install the clang formatting git hooks. From the root of the repo, simply run

`./tools/install-hooks.sh .`

If you have `clang-format` installed on your machine, it will check your commits and fix the formatting on them to keep things consistent. If something violates the clang format, it will give you instructions to add a patch to fix it. After applying the patch, re-add and re-commit the code and it should pass through.

**NOTE** - if `clang-format` is not installed, this won't do anything or even print a warning, which is annoying. 

------------
# Command line
------------

To run the code with a given input file in the input/ directory, type
`./exec/MultiBGK_ input_filename`

You can also run with the optional arguments `restartFlag` and `tauflag`

`./exec/MultiBGK_ input_filename restartFlag tauflag `

you can pick three things for `restartFlag`

0: Runs 'original' version, that does not dump distribution functions or load them from a file (default if not specified)
1: The code itself sets the initial conditions as usual, but stores the distribution functions at the final timestep. Use this if you are starting a new run that you will want to restart later.
2: The code loads initial distribution function data generated by an earlier run of the code. It again dumps the distribution function data at the end of its run.
3: The code sets initial conditions as usual, but stops based on a RHS related criteria that indicates that the collision rates have gone stale (set in the input file). This dumps the distributions at its last timestep.
4: The code loads initial distribution function data from an earlier run, and stops as in option 3 when the collision rates are determined to be 'stale', dumping the distributions. 

you can pick two things for `tauflag`

0: Runs original version, choosing the tau based on the collision rate formulas and the flags in the input files
1: Loads tau values from the file Data/input_filename_tau.dat
This assumes the taus are written out in human-readable format (non-binary), one per line in the file, e.g.
```1.23742e-12
4.18151e-13
2.12590e-10
3.1251e-5```

This is in row major ordering, so the example above would correspond to
```tau[0][0]
tau[0][1]
tau[1][0]
tau[1][1]```

-----------
# INPUT FILES
-----------

The input files look for certain keywords, then their values listed in the following line(s). Keywords are


## Species info

`nspec`                  - number of species 

`mass`                   - reads in masses of each species, given in grams. Possible future feature will allow for certain preloaded species (e.g. D,T,e)

`Z`                      - Atomic number for each species (e.g. 1 for H). 

## physical space info

`dims`                   - 0 for 0D-3V 
		       - 1 for 1D-3V 

`Nx`                     - number of grid points in physical space (default 32)

`Lx`                     - width of physical space (in cm) (default 1e-6)

## Velocity space info

`Nv`                     - number of velocity grid points in one direction. Total number is Nv*Nv*Nv (default 40)

`discret`		  - 0 for uniform velocity grid
		         - 1 for gauss legendre velocity grid (default, but not recommended for 1D3V problems)

`v_width`                - width of velocity grid, in terms of a multiple each species's thermal speed (default 6)


## Time info

`Time_step`              - time step (in sec)  (default 1e-16)

`Final_time`             - length of time to simulate (in s) (default 1e-12)

`Space_order`            - Whether to use first or second order method for time stepping/discretization (Int 1 or 2)


##  Electric field info

`poiss`                  - type of Poisson solver to use for 1D problems
		       - 0: no Poisson solve (E field set to 0) 
		       - 11: Linearized Yukawa model
		       - 12: Nonlinear Yukawa model
		       - 21: Linearized Thomas-Fermi model
		       - 22: Nonlinear Thomas-Fermi model (default)		


`Te_start` 	       - Initial background electron temperature, used if ecouple = 1

`Te_end`  	       - Final background electron temperature, used if ecouple = 1
		       - If Te_end != Te_start, the electron temperature is linearly ramped 
		       - from Te_star to Te_end over the simulation time.



## Collision info

`BGKtype`		       - Flag that determines which multi-BGK model to use
		       	 + 0 - Haack, Hauck, Murillo (default)
			 + 1 - Greene
			 + 2 - NRL

`beta`		       - Free parameter used in Greene BGK model (default 0)

`ecouple` 	       - Flag to determine how to deal with electrons. 
		       - 0: All species are ions (default)
		       - 1: electrons as background show up in collision operators. 
		       - 2: electrons are a species, MUST BE SPECIES 0, to tell what collision rates to use.

`Coulomb_type`	       - 0: use GMS coulomb log when appropriate (default)
		       - 1: use NRL coulomb log when appropriate

`Ion_coll_type`	       - 0: Use Stanton-Murillo cross section data to derive collision rates, Landau-Spitzer if electrons are involved (default)
		       - 1: Use NRL collision rates		       

`Ion_coll_flavor`	       - 0: use momentum relaxation rates to determine nu (default)
		       - 1: use temperature relaxation rates to determin nu


## OD Setup

`n`                      - reads in initial number densities for each species in cc. Only used for 0D.

`v`                      - reads in initial bulk velocities for each species in cm/s. This is just v_1, the others are assumed to be 0 for now. Only used for 0D.

`T`                      - reads in initial temperatures for each species in eV. Only used for 0D.


## 1D Setup

This initializes to Maxwellians in specific intervals

`NumIntervals`           - Sets the number of intervals with different ICs. Opens initialization region

`Interval`               - Changes active interval and labels it with specified number (count up from one)

`x`                      - specifies left most boundary of active interval

`n_i` 		       - specifies number densities (1/cm^3) of each species in active interval (one species per line)

`v_i`		       - specifies x velocities (cm/s) of each species in active interval

`T_i`		       - specifies temperatures (ev) of each species in active interval

`End_int`		       - closes initial condition specification

Example - for MOD-MD initial condition on domain of [-1e-4, 1e-4]:

```
NumIntervals
2
Interval
1
x
-1e-4
n_i
4.663e22
6.305e22
5.51e20
0
0
v_i
0.0
0.0
0.0
0.0
0.0
T_i
10
10
10
0
0
Interval
2
x
0
n_i
0
0
0
2.994e22
2.994e22
v_i
0.0
0.0
0.0
0.0
0.0
T_i
0.0
0.0
0.0
10.0
10.0
End_init
```

## output options


`Data_writing_frequency` - Number of time steps between writes to output files (Int) (default 1)

`Dump_distro`            - Flag for outputting the full vdf for 1D-3V at the writing frequency rate
		       - Set to 1 to include distribution functions whenever output is written to disk
		       - default is 0
		       - I think this is only implemented for 1D-3V right now
		       - WARNING: this can generate a ton of data if you are not careful with how often you report your data. Make sure you do not have a writing frequency of e.g. 1 if you use this.

`RHS_tol`		       - This sets the threshold in which the relative error(s) between f and f_eq indicate that we should stop. We compute ||f - f_eq||^2_{ij} / ||f_init - f_eq,init||^2_{ij}, which is a decreasing quantity. Default value is 0.5. 

## In development

`Imp_exp`		       - Whether to do implicit or explicit time discretization of BGK (0 for exp, 1 for imp)
		       - default is 0		       
		       - Note - this is a placeholder, implicit currently does not work

`hydro_flag`             - 0: run the code as designed (default)
		       - 1: Reset the distribution function to its local Maxwellian, ala Kinetic scheme

The order you put these in the file mostly does not matter, though you do need nspec before anything that requires knowing the number of species (e.g. masses)


