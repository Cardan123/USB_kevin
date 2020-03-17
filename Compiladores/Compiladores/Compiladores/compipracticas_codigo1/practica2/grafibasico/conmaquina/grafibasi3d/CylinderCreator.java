import javax.media.j3d.BranchGroup;
import javax.media.j3d.Appearance;
import javax.media.j3d.TransformGroup;
import javax.media.j3d.Transform3D;
import javax.vecmath.Point3d;
import javax.vecmath.Vector3d;
import javax.vecmath.Matrix4d;
import com.sun.j3d.utils.geometry.Cylinder;


/**
 * This class creates a Cylinder in whatever orientation YOU want!
 * <p>
 * Provide two endpoints, and this will do the necessary transformations on
 * the Java3D Cylinder class for you, returning the Cylinder in a BranchGroup.
 *
 * @author Scott Teresi, March 1999, www.teresi.us
 *
 */



public class CylinderCreator {

  int edges;


  /**
   * Constructs a cylinder with 7 edges by default.
   */

  public CylinderCreator() {
    edges = 7;    // e.g. "edges = 8" would look like a stop sign
  }


  /**
   * Sets the resolution (number of edges) of the Cylinder.
   * @param e Number of edges (e.g. 8 would look like a stop sign).
   */

  public void setResolution(int e) {
    edges = e;
  }
  

  /**
   * Creates a cylinder.
   * @return A BranchGroup containing the cylinder in the desired orientation.
   * @param b coordinates of the base of the cylinder.
   * @param a coordinates of the top of the cylinder.
   * @param radius radius of the cylinder.
   * @param cylApp cylinder Appearance.
   */

  public BranchGroup create (Point3d b, Point3d a, double radius,
			     Appearance cylApp) {

    Vector3d base = new Vector3d();
    base.x = b.x;
    base.y = b.y;
    base.z = b.z;
    Vector3d apex = new Vector3d();
    apex.x = a.x;
    apex.y = a.y;
    apex.z = a.z;

    // calculate center of object
    Vector3d center = new Vector3d();
    center.x = (apex.x - base.x) / 2.0 + base.x;
    center.y = (apex.y - base.y) / 2.0 + base.y;
    center.z = (apex.z - base.z) / 2.0 + base.z;

    // calculate height of object and unit vector along cylinder axis
    Vector3d unit = new Vector3d();
    unit.sub(apex, base);  // unit = apex - base;
    double height = unit.length();
    unit.normalize();

    /* A Java3D cylinder is created lying on the Y axis by default.
       The idea here is to take the desired cylinder's orientation
       and perform a tranformation on it to get it ONTO the Y axis.
       Then this transformation matrix is inverted and used on a
       newly-instantiated Java 3D cylinder. */

    // calculate vectors for rotation matrix
    // rotate object in any orientation, onto Y axis (exception handled below)
    // (see page 418 of _Computer Graphics_ by Hearn and Baker)
    Vector3d uX = new Vector3d();
    Vector3d uY = new Vector3d();
    Vector3d uZ = new Vector3d();
    double magX;
    Transform3D rotateFix = new Transform3D();

    uY = new Vector3d(unit);
    uX.cross(unit, new Vector3d(0, 0, 1));
    magX = uX.length();
    // magX == 0 if object's axis is parallel to Z axis
    if (magX != 0) {
      uX.z = uX.z / magX;
      uX.x = uX.x / magX;
      uX.y = uX.y / magX;
      uZ.cross(uX, uY);
    }
    else {
      // formula doesn't work if object's axis is parallel to Z axis
      // so rotate object onto X axis first, then back to Y at end
      double magZ;
      // (switched z -> y, y -> x, x -> z from code above)
      uX = new Vector3d(unit);
      uZ.cross(unit, new Vector3d(0, 1, 0));
      magZ = uZ.length();
      uZ.x = uZ.x / magZ;
      uZ.y = uZ.y / magZ;
      uZ.z = uZ.z / magZ;
      uY.cross(uZ, uX);
      // rotate object 90 degrees CCW around Z axis--from X onto Y
      rotateFix.rotZ(Math.PI / 2.0);
    }

    // create the rotation matrix
    Transform3D transMatrix = new Transform3D();
    Transform3D rotateMatrix =
	new Transform3D(new Matrix4d(uX.x, uX.y, uX.z, 0,
				     uY.x, uY.y, uY.z, 0,
				     uZ.x, uZ.y, uZ.z, 0,
				     0,  0,  0,  1));
    // invert the matrix; need to rotate it off of the Z axis
    rotateMatrix.invert();
    // rotate the cylinder into correct orientation
    transMatrix.mul(rotateMatrix);
    transMatrix.mul(rotateFix);
    // translate the cylinder away
    transMatrix.setTranslation(center);
    // create the transform group
    TransformGroup tg = new TransformGroup(transMatrix);

    Cylinder cyl = new Cylinder((float) radius, (float) height,
				Cylinder.GENERATE_NORMALS, edges, 1, cylApp);
    tg.addChild(cyl);
    BranchGroup cylBg = new BranchGroup();
    cylBg.addChild(tg);
    return cylBg;
  }


}
