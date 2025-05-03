# Input file for uniaxial tensile loading of single crystal aluminum
# Mark Tschopp, November 2010

# ------------------------ INITIALIZATION ----------------------------
units           metal                ##SO THIS SECTION EXPLAINS THE BASIC SKELETON
dimension	3
boundary	p	p	p               ##p means periodic boundaries in all 3 directions to mimic an infinitely large continuous system
atom_style	atomic
variable latparam equal 4.05   #LATTICE PARAMETER 

# ----------------------- ATOM DEFINITION ----------------------------
lattice		fcc ${latparam}
region		whole block 0 10 0 10 0 10   #THE 'WHOLE' SIMULATION REGION IS A CUBE OF SIDE 10 UNITS
create_box	1 whole
lattice 	fcc ${latparam} orient x 1 0 0 orient y 0 1 0 orient z 0 0 1 #value of latparam variable is 4.05
create_atoms	1 region whole

# ------------------------ FORCE FIELDS ------------------------------
pair_style	eam/alloy  #EMBEDDED ATOM MODEL FILE, CONTAINS INFORMATION ON POTENTIALS AND INTERNAL ENERGIES
pair_coeff	* * Al99.eam.alloy Al

# ------------------------- SETTINGS ---------------------------------
compute csym all centro/atom fcc
compute peratom all pe/atom 

######################################
# EQUILIBRATION
reset_timestep	0
timestep 0.002  #HOW OFTEN THE FRAME CHANGES (in picosec) so 1 femto sec

velocity all create 300 12345 mom yes rot no

#velocity command sets the intial velocities based on given parameters 
#here we initialize the temperature to 300k, no momentum in system, no rotation of atoms (only translation motion is taken into consideration (related to degrees of freedom)).

fix 1 all npt temp 300 300 1 iso 0 0 1 drag 1 

#the fix keyword helps in callibrating temperature and pressure values with respect to each other, so that a constant temperature and pressure environment is maintained.
#drag simulates the frictional effect. more the drag value, faster the system slows down.


# Set thermo output
thermo 1000   #OUTPUTS THERMODYNAMIC DATA EVERY 1000 TIMESTEPS

thermo_style custom step lx ly lz press pxx pyy pzz pe temp

#px,py,pz is stress along these directions, then we have pe : potential energy : then we have temp

# Run for at least 10 picosecond (assuming 1 fs timestep)
run 10000
unfix 1

# Store final cell length for strain calculations
variable tmp equal "lx"
variable L0 equal ${tmp}
print "Initial Length, L0: ${L0}"

######################################
# DEFORMATION
reset_timestep	0

fix		1 all npt temp 300 300 1 y 0 0 1 z 0 0 1 drag 1
#NOW WE ARE GOING TO DEFORM

variable srate equal 1.0e10
variable srate1 equal "v_srate / 1.0e12"
fix		2 all deform 1 x erate ${srate1} units box remap x

# Output strain and stress info to file
# for units metal, pressure is in [bars] = 100 [kPa] = 1/10000 [GPa]
# p2, p3, p4 are in GPa
variable strain equal "(lx - v_L0)/v_L0"
variable p1 equal "v_strain"
variable p2 equal "-pxx/10000"
variable p3 equal "-pyy/10000"
variable p4 equal "-pzz/10000"
variable bulk_mod equal "-(pxx + pyy + pzz)/3.0e4"  # Bulk modulus in GPa
fix def1 all print 100 "${p1} ${p2} ${p3} ${p4}" file Al_SC_100.def1.txt screen no

# Use cfg for AtomEye
dump 		1 all cfg 250 dump.tensile_*.cfg mass type xs ys zs c_csym c_peratom fx fy fz
dump_modify 1 element Al

# Display thermo
thermo 	1000
thermo_style	custom step v_strain temp v_p2 v_p3 v_p4 ke pe press v_bulk_mod

run		10000

######################################
# SIMULATION DONE
print "All done"
