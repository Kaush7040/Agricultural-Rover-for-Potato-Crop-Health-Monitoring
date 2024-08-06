import streamlit as st
import matplotlib.pyplot as plt
import numpy as np

def draw_star():
    fig, ax = plt.subplots()
    ax.set_aspect('equal')
    ax.axis('off')

    # Set background color to grass green
    fig.patch.set_facecolor('#7CFC00')
    ax.set_facecolor('#7CFC00')

    # Star coordinates
    angles = np.linspace(0, 2 * np.pi, 10, endpoint=False)
    radius = 100
    star_points = []

    for i in range(10):
        if i % 2 == 0:
            star_points.append((radius * np.cos(angles[i]), radius * np.sin(angles[i])))
        else:
            star_points.append((radius * 0.5 * np.cos(angles[i]), radius * 0.5 * np.sin(angles[i])))

    star_points = np.array(star_points)
    star_points = np.append(star_points, [star_points[0]], axis=0)  # Close the star shape

    # Plot the star in dirt brown with a thicker line
    ax.plot(star_points[:, 0], star_points[:, 1], color='#8B4513', linewidth=3)

    # Close the plot
    plt.close(fig)
    
    return fig

st.title("🌱Agri Map🌱")
st.write("Map of your field is displayed here:")
btn = st.button("Generate Map")

if btn:
    fig = draw_star()
    st.pyplot(fig)
