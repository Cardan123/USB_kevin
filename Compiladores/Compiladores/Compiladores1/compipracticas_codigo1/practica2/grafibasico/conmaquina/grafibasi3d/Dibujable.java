import java.awt.*;
import javax.media.j3d.*;
interface Dibujable {
	//void dibujar(Graphics g);
        void dibujar(BranchGroup bg, CylinderCreator cylinder, Appearance branchApp);
        void transladar(double dx, double dy);
        void escalar(double dx, double dy);
}
